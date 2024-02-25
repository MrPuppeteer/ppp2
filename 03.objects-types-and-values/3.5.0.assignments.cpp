#include "std_lib_facilities.h"
int main()
{
  int a = 3;  // a starts out with the value 3
  a = 4;      // a gets the value 4 ("becomes 4")
  int b = a;  // b starts out with a copy of a's value (that is, 4)
  b = a+5;    // b gets the value a+5 (that is, 9)
  a = a+7;    // a gets the value a+7 (that is, 11)

  int x = 8;  // initialize x with 8
  x = 9;      // assign 9 to x
}
