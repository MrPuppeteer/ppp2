#include "std_lib_facilities.h"

int main()
{
  cout << "Enter two integer values:\n";
  int val1, val2;
  cin >> val1 >> val2;

  if (val1 < val2)
    cout << val1 << " is the smaller one and " << val2 << " is larger\n";
  else if (val2 < val1)
    cout << val2 << " is the smaller one and " << val1 << " is larger\n";
  else
    cout << val1 << " is equivalent to " << val2 << "\n";

  cout << "The sum of " << val1 << " and " << val2
       << " is " << val1 + val2 << '\n'

       << "The difference between " << val1 << " and " << val2
       << " is " << val1 - val2 << '\n'

       << "The product of " << val1 << " and " << val2
       << " is " << val1 * val2 << '\n'

       << "The ratio of " << val1 << " and " << val2
       << " is " << val1 / val2 << '\n';
}
