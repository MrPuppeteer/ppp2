#include "std_lib_facilities.h"

// Convert from miles to Kilometers
int main()
{
  cout << "Enter a number of miles:\n";
  double miles;
  cin >> miles;
  cout << miles << " miles is equivalent to " << miles * 1.609 << "km\n";
}
