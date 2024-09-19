#include "std_lib_facilities.h"

int square(int);      // declaration of square
double sqrt(double);  // declaration of sqrt

int main() {
  for (int i = 0; i<100; ++i)
    cout << i << '\t' << square(i) << '\n';
}

int square(int x) { // return the square of x
  return x*x;
}
