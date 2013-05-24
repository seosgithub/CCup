#include <stdio.h>
#include "CCup.h"

int main() {
  CCup(function() {
      CCSelfTest();

      CCOn("test");
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
      });
  });

  while (true) {
  }

  return 0;
}
