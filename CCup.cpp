#include "CCup.h"

static int doneTimeout = 1;  //Number of seconds to wait for done to be called
void SetTimeout(int x) {
  doneTimeout = x;
}

static sem_t *doneSemaphore;

#define function() ^()
#define _function() ^(DoneFunction done)

//Done was never reached in time
void HandleFailedDone(int) {
  printf("✖\n");
  fprintf(stderr, "\n---------------------------------------\n");
  fprintf(stderr, "Test failed! Timeout of %i seconds reached", doneTimeout);
  fprintf(stderr, "\n---------------------------------------\n");
  exit(EXIT_FAILURE);
}

//Thread that handles the actual unit tests
void *CCupThread(void *_tests) {
  UnitTests tests = (UnitTests)_tests;

  //Handle done timeouts
  signal(SIGALRM, HandleFailedDone);

  //Setup semaphore
  srand(time(NULL));
  char randomName[20];
  randomName[sizeof(randomName)-1] = 0;
  for (int i = 0; i < sizeof(randomName)-1; ++i)
    randomName[i] = 'A'+rand()%10;
  doneSemaphore = sem_open(randomName, O_CREAT, O_RDWR, 0);
  if (doneSemaphore == (int *)-1) {
    fprintf(stderr, "CCup could not create done semaphore, error code: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("++++++++++++++++++++++++++++++++\n");
  printf("Starting unit tests!\n");
  printf("++++++++++++++++++++++++++++++++\n");

  //Run all
  tests();

  printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  printf("Tests passed!\n");
  printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

  return NULL;

}

//Setup CCup
void CCup(UnitTests tests) {
  pthread_t ccupThread;
  pthread_create(&ccupThread, NULL, CCupThread, tests);
}

//Describe something
void Describe(const char *message, UnitTests tests) {
  printf(">%s\n", message);
  tests();
}

//It 'does' something
void It(const char *message, UnitTests tests) {
  printf("\t+%s ", message);
  fflush(stdout);
  tests();
  printf("\n");
}

void Done() {
  sem_post(doneSemaphore);
  alarm(0);
}

//It 'does' something
void It(const char *message, UnitTestsWithDone tests) {
  alarm(doneTimeout);
  printf("\t+%s ", message);
  fflush(stdout);
  tests(Done);
  sem_wait(doneSemaphore);
  printf("\n");
}


//Asserts
//#######################################
void IsEqual(float a, float b) {
  if (a != b) {
    printf("✖\n");
    fprintf(stderr, "\n---------------------------------------\n");
    fprintf(stderr, "Test failed!  %f != %f", a, b);
    fprintf(stderr, "\n---------------------------------------\n");
    exit(EXIT_FAILURE);
  }
  printf("✔");
}

void IsTrue(int a) {
  if (!a) {
    printf("✖\n");
    fprintf(stderr, "\n---------------------------------------\n");
    fprintf(stderr, "Test failed! Not True");
    fprintf(stderr, "\n---------------------------------------\n");
    exit(EXIT_FAILURE);
  }
  printf("✔");
}

//Messaging
//######################################
std::map<std::string, sem_t *> inboundMessageSemaphores;
std::map<std::string, pthread_mutex_t> inboundMessageMutexes;

typedef std::queue<CCupMessage_t> MessageQue_t;
std::map<std::string, MessageQue_t> inboundMessages;

int DoesQueExist(std::string name) {
  std::map<std::string, sem_t *>::iterator i = inboundMessageSemaphores.find(name);

  return i != inboundMessageSemaphores.end();
}

void CreateSemaphore(std::string name) {
  //Create random name
  char randomName[20];
  randomName[19] = 0;
  for (int i = 0; i < sizeof(randomName)-1; ++i)
    randomName[i] = 'A' + rand()%20;

  //Create a semaphore
  inboundMessageSemaphores[name] = sem_open(randomName, O_CREAT, O_RDWR, 0);
  if (inboundMessageSemaphores[name] < 0) {
    fprintf(stderr, "Could not create semaphore for CCup messages!  Error code: %d\n", errno);
    exit(EXIT_FAILURE);
  }
}

void CreateMutex(std::string name) {
  //Create a mutex
  int res = pthread_mutex_init(&inboundMessageMutexes[name], NULL);
  if (res < 0) {
    fprintf(stderr, "Could not create mutex for CCup messages!  Error code: %d\n", errno);
    exit(EXIT_FAILURE);
  }
}

sem_t *GetSemaphore(std::string name) {
  return inboundMessageSemaphores[name];
}

pthread_mutex_t GetMutex(std::string name) {
  return inboundMessageMutexes[name];
}

MessageQue_t &GetMessageQue(std::string name) {
  return inboundMessages[name];
}

void LazyLoadQue(std::string name) {
  if (!GetSemaphore(name)) {
    CreateSemaphore(name);
    CreateMutex(name);
  }
}

void CCSend(std::string name, const char *data, int len) {
  LazyLoadQue(name);
  
  pthread_mutex_lock(&inboundMessageMutexes[name]);

  CCupMessage_t message;
  memcpy(&message.data, data, len);
  message.len = len;
  inboundMessages[name].push(message);
  sem_post(inboundMessageSemaphores[name]);

  pthread_mutex_unlock(&inboundMessageMutexes[name]);
}

CCupMessage_t CCGet(std::string name) {
  LazyLoadQue(name);

  CCupMessage_t message;

  //Wait for a message
  int res = sem_wait(inboundMessageSemaphores[name]);
  if (res < 0) {
    fprintf(stderr, "Tried to wait for semaphore, got error code: %i\n", errno);
    exit(EXIT_FAILURE);
  }

  pthread_mutex_lock(&inboundMessageMutexes[name]);

  message = GetMessageQue(name).front();
  GetMessageQue(name).pop();

  pthread_mutex_unlock(&inboundMessageMutexes[name]);
  return message;
}
