#include "std_lib_facilities.h"

int area(int length, int width)
// calculate area of a rectangle;
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is the area
{
  if (length <= 0 || width <= 0)
    error("area() pre-condition");
  int a = length * width;
  if (a <= 0)
    error("area() post-condition");
  return a;
}

int main()
// If length and/or width is too large, it will result overflow
// that means the pre-condition may holds, but the post-condition may doesn't
try
{
  int length = 0;
  int width = 0;
  cout << "Enter the length and width to get the area of a rectangle: ";
  cin >> length >> width;
  cout << "Area is " << area(length, width) << '\n';
  return 0;
}
catch (runtime_error &e)
{
  cout << "Error: " << e.what() << '\n';
  return 1;
}
catch (...)
{
  cout << "Error: unknown exception\n";
  return 2;
}
