#include "std_lib_facilities.h"

int area(int length, int width) // calculate area of a rectangle
{
  if (length <= 0 || width <= 0)
    error("non-positive area() argument");
  return length * width;
}

int framed_area(int x, int y) // calculate area within frame
{
  constexpr int frame_width = 2;
  if (x - frame_width <= 0 || y - frame_width <= 0)
    error("non-positive area() argument called by framed_area()");
  return area(x - frame_width, y - frame_width);
}

int main()
{
  int x = -1;
  int y = 2;
  int z = 4;
  int area1 = area(x, y);
  int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = double(area1) / area3; // convert to double to get
                                        // floating-point division
}
