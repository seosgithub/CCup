CCup
====

Authors: Seo Townsend 2013

C unit testing that makes sense based on jasmine, nodeunit, etc.

Supports asynchronous testing!  (Without the headache).

So unit testing in C sucks.  (That is, until now!)
====

Steps
==

Add CCup.h to your project and off you go!

'''c
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
          sleep(1);
          done();
        });
      });
  });

  while (true) {
  }
  return 0;
}
'''
