#ifndef CCUP_H_
#define CCUP_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>

typedef void (*DoneFunction)();
typedef void (^UnitTests)();
typedef void (^UnitTestsWithDone)(DoneFunction);

static int doneTimeout = 1;  //Number of seconds to wait for done to be called
void SetTimeout(int x) {
  doneTimeout = x;
}

//Mutex lockout to wait for done function
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

void done() {
  sem_post(doneSemaphore);
  alarm(0);
}

//It 'does' something
void It(const char *message, UnitTestsWithDone tests) {
  alarm(doneTimeout);
  printf("\t+%s ", message);
  fflush(stdout);
  tests(done);
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

#endif
