#include "std_lib_facilities.h"

int main()
{
  double x = 2.7;
  // lots of code
  int y = x;  // y becomes 2

  int a = 1000;
  char b = a; // b becomes -24 (on some machines)

  // double x {2.7}; // OK
  // int y {x};      // error: double -> int might narrow
  // int a {1000};   // OK
  // char b {a};     // error: int -> char might narrow

  // int char b1 {1000}; // error: narrowing (assuming 8-bit chars)
  // char b2 {48};       // OK
}
