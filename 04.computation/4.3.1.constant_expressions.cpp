#include "std_lib_facilities.h"

int main() {
  // constexpr double pi = 3.14159;
  constexpr double pi = 3.14159265359;

  // pi = 7;          // error: assignment to constant
  
  int r = 7;
  double c = 2*pi*r;  // OK: we just read pi; we don't try to change it

  //------------------------------------------------------------------//
  
  constexpr int max = 17; // a literal is a constant expression
  int val = 19;

  max+2;  // a constant expression (a const int plus a literal)
  val+2;  // not a constant expression: it uses a variable

  //------------------------------------------------------------------//
}

constexpr int maxi = 100;
void use(int n) {
  constexpr int c1 = maxi+7; // OK: c1 is 107
  // constexpr int c2 = n+7;   // error: we don't know the value of c2
  const int c2 = n+7;        // OK, but don't try to change the value of c2
  // ...
  // c2 = 7;                   // error: c2 is a const
}
