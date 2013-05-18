#include <stdio.h>
#include "CCup.h"

int main() {
  CCup(function() {
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
          SendIt("test", str, 5);
          CCupMessage_t message = WaitForIt("test");
          IsTrue(!strcmp(message.data, "lol?"));

          done();
        });
      });
  });

  while (true) {
  }

  return 0;
}
