CCup - The best C unit testing framework.
====

Authors: Seo Townsend 2013

C unit testing that makes sense based on jasmine, nodeunit, etc.

Supports asynchronous testing!  (Without the headache).

```c
#include <stdio.h>
#include "CCup.h"

int main() {
  CCup(function() {
      Describe("My heart", function() {
        It("is real", function() {
          IsEqual(1, 1);
        });

        //Test async code
        SetTimeout(2);
        It("does beat", _function() {
          IsEqual(1, 1);
          sleep(1);
          done();
        });
      });
  });

  while (true) {
  }

  return 0;
}
```
