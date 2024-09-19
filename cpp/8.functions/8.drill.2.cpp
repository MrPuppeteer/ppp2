#include "std_lib_facilities.h"

void swap_v(int a, int b)
{  int temp; temp = a; a = b; b = temp; }

void swap_r(int &a, int &b)
{  int temp; temp = a; a = b; b = temp; }

/*
 * Compile error, since a constant value can't be changed
void swap_cr(const int &a, const int &b)
{  int temp; temp = a; a = b; b = temp; }
 */

int main()
{
  int x = 7;
  int y = 9;

  // swap_v(x, y); // compiles, does nothing (only the copy of values get swapped)
  swap_r(x, y); // compiles, it does swap the values (pass-by-reference)
  
  cout << x << ' ' << y << '\n';

  swap_v(7, 9); // same as line 20
  // swap_r(7, 9); // compile error, since there is no name to be referenced

  const int cx = 7;
  const int cy = 9;

  swap_v(cx, cy); // same as line 20
  // swap_r(cx, cy); // compile error, since constant values can't be changed

  cout << cx << ' ' << cy << '\n';

  swap_v(7.7, 9.9); // same as line 20, except implicit conversion double to int
  // swap_r(7.7, 9.9); // same as line 26

  double dx = 7.7;
  double dy = 9.9;

  swap_v(dx, dy); // same as line 36
  // swap_r(dx, dy); // same as line 32

  cout << dx << ' ' << dy << '\n';

  // swap_?(7.7, 9.9); // duplicate
}
