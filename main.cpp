#include <stdio.h>
#include "CCup.h"

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
  /*});*/

  CCup(function() {
      CCSend("Test", "hello", 5);
      char data[] = {1, 1, 0};
      CCSend("Rawr", data, sizeof(data));
  });

  while (true) {
  }

  return 0;
}
