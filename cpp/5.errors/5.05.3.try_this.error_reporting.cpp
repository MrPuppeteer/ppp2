#include "std_lib_facilities.h"

// ask user for a yes-or-no answer;
// return 'b' to indicate a bad answer (i.e., not yes or no)
char ask_user(string question)
{
  cout << question << "? (yes or no)\n";
  string answer = " ";
  cin >> answer;
  if (answer == "y" || answer == "yes")
    return 'y';
  if (answer == "n" || answer == "no")
    return 'n';
  return 'b'; // 'b' for "bad answer"
}

// calculate area of a rectangle
// return -1 to indicate a bad argument
int area(int length, int width)
{
  if (length <= 0 || width <= 0)
    return -1;
  return length * width;
}

int framed_area(int x, int y) // calculate area within frame
{
  constexpr int frame_width = 2;
  return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z)
{
  int area1 = area(x, y);
  if (area1 <= 0)
    error("non-positive area");
  // int area2 = framed_area(1,z);
  int area3 = framed_area(y, z);
  if (area3 <= 0)
    error("non-positive area");
  double ratio = double(area1) / area3;
  cout << "area1: " << area1
       << "\narea3: " << area3
       << "\nratio: " << ratio << '\n';
  return 0;
}

int main()
{
  int x, y, z;
  while (cin >> x >> y >> z)
  {
    cout << "x: " << x << "\ny: " << y << "\nz: " << z << '\n';
    f(x, y, z);
  }
}
