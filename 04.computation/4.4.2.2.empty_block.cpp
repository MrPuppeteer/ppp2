#include "std_lib_facilities.h"

int main() {
  int a = 7;
  int b = 4;

  if (a<=b) { // do nothing
  } else {    // swap a and b
    int t = a;
    a = b;
    b = t;
  }
}
