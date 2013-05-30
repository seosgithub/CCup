#ifndef CCUP_H_
#define CCUP_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>
#include <map>
#include <string>
#include <queue>
#include "Network.h"

//Useful to check in files to see what sections to exclude
#define CCUP

typedef void (*DoneFunction)();
typedef void (^UnitTests)();
typedef void (^UnitTestsWithDone)(DoneFunction);

void SetTimeout(int x);

#define function() ^()
#define _function() ^(DoneFunction done)

//Setup CCup
void CCup(UnitTests tests);

//Describe something
void Describe(const char *message, UnitTests tests);

//It 'does' something (Non-async)
void It(const char *message, UnitTests tests);

//It does something and waits for CCDone
void It(const char *message, UnitTestsWithDone tests);

//Assert equality
void IsEqual(float a, float b);
void IsEqualString(const char *a, const char *b);
void IsEqualData(const unsigned char *a, const unsigned char *b, int len);

//Assert it is true
void IsTrue(int a);

//Self Testing
//######################################
void CCSelfTest();

//Messaging
//######################################
struct CCupMessage_t {
  int len;
  char data[200];
};

//Send a message
void CCSend(std::string name, const char *data, int len);
void CCSend(std::string name, int value);

//Get a message (Block until)
CCupMessage_t CCGet(std::string name);
int CCGetValue(std::string name);

//Get the number of messages in the que
int CCCount(std::string name);

//Reset que
void CCReset(std::string name);

//Enable / Disable a message (Enabled by default)
void CCOn(std::string name);
void CCOff(std::string name);

#endif
