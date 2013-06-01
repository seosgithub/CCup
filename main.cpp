#include <stdio.h>
#include <pthread.h>
#include "CCup.h"

void *ThreadA(void *a) {
  for (int i = 0; i < 2; ++i) {
    CCSend("Test", "ThreadA", 8);
    CCSend("Test", "ThreadA", 8);
    //CCGet("Test");
    printf("A\n");
  }

  return NULL;
}

void *ThreadB(void *b) {
  for (int i = 0; i < 1000; ++i) {
    CCSend("Test", "ThreadB", 8);
    CCSend("Test", "ThreadB", 8);
    CCGet("Test");
    printf("B\n");
  }

  return NULL;
}

int main() {
  //Regular
  /*CCup(function() {*/
      //CCSelfTest();

      //Describe("test", function() {
        //It("hey", function() {
          //IsEqual(1, 1);
          //IsEqual(1, 1);
          //IsEqual(1, 1);
        //});

        //SetTimeout(2);

        //It("Also does so", _function() {
          //IsEqual(1, 1);

          ////Wait for a message
          //const char str[] = "lol?";
          //for (int i = 0; i < 100; ++i)
            //CCSend("test", str, 5);
          //CCupMessage_t message = CCGet("test");
          //IsTrue(!strcmp(message.data, "lol?"));
          //done();
        //});

        //It("Can pass messages as integer values", function() {
          //CCSend("Another", 7);
          //int value = CCGetValue("Another");
          //IsEqual(value, 7);
        //});

        //It("Knows how many messages are left in the que", function() {
            //CCSend("Test", 4);
            //CCSend("Test", 4);
            //int numberWaiting = CCCount("Test");
            //IsEqual(numberWaiting, 2);
        //});

        //It("Can reset the que", function() {
            //CCSend("Test", 4);
            //CCSend("Test", 4);
            //CCReset("Test");
            //int numberWaiting = CCCount("Test");
            //IsEqual(numberWaiting, 2);
        //});


        //It("Can pass messages as integer values (multiple)", function() {
          //CCSend("Another", 3);
          //CCSend("Another", 4);
          //int value = CCGetValue("Another");
          //IsEqual(value, 3);
          //value = CCGetValue("Another");
          //IsEqual(value, 4);
        //});

      //});
  //});

  //[>CCup(function() {<]
      ////CCSend("Test", "hello", 5);
      ////char data[] = {1, 1, 0};
      ////CCSend("Rawr", data, sizeof(data));
  /*[>});<]*/

  CCup(function() {
    puts("Starting CCup");

    //Attempt to send data in multiple threads
    pthread_t threadA;
    pthread_t threadB;
    int res = pthread_create(&threadA, NULL, ThreadA, NULL);
    if (res != 0) {
      fprintf(stderr, "Pthread could not create thread A\n");
      exit(EXIT_FAILURE);
    }

    /*res = pthread_create(&threadB, NULL, ThreadB, NULL);*/
    //if (res != 0) {
      //fprintf(stderr, "Pthread could not create thread B\n");
      //exit(EXIT_FAILURE);
    /*}*/

    sleep(1);
    for (int i = 0 ; i < 4; ++i)
      CCGet("Test");


    Describe("Threading is supported", function() {
      IsEqual(CCCount("Test"), 0);
    });
  });

  while (true) {
    sleep(1);
  }

  return 0;
}
