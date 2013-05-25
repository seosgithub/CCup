#include <stdio.h>
#include "CCup.h"

int main() {
  CCup(function() {
      CCSelfTest();

      Describe("test", function() {
        It("hey", function() {
          IsEqual(1, 1);
          IsEqual(1, 1);
          IsEqual(1, 1);
        });

        SetTimeout(2);

        It("Also does so", _function() {
          IsEqual(1, 1);

          //Wait for a message
          const char str[] = "lol?";
          for (int i = 0; i < 100; ++i)
            CCSend("test", str, 5);
          CCupMessage_t message = CCGet("test");
          IsTrue(!strcmp(message.data, "lol?"));
          done();
        });

        It("Can pass messages as integer values", function() {
          CCSend("Another", 7);
          int value = CCGetValue("Another");
          IsEqual(value, 7);
        });

        It("Can pass messages as integer values (multiple)", function() {
          CCSend("Another", 3);
          CCSend("Another", 4);
          int value = CCGetValue("Another");
          IsEqual(value, 3);
          value = CCGetValue("Another");
          IsEqual(value, 4);
        });

      });
  });

  while (true) {
  }

  return 0;
}
