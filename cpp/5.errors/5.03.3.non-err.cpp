#include "std_lib_facilities.h"

int area(int length, int width);

int main()
{
  int x4 = area(10, -7);     // OK: but what is a rectangle with a width of minus 7?
  int x5 = area(10.7, 9.3);  // OK: but calls area(10,9)
  char x6 = area(100, 9999); // OK: but truncates the result
}
