#include "std_lib_facilities.h"

// Determine if an integer is odd or even
int main()
{
  int x = 0;
  cout << "Please enter an integer: ";
  cin >> x;

  cout << "The value " << x << " is an "
       << ((x%2) ? "odd" : "even")
       << " number\n";
}
