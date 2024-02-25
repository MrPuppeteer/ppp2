#include "std_lib_facilities.h"

// Determine the smaller, larger, sum, difference, product, and ratio of two double values
int main()
{
  double val1 = 0;
  double val2 = 0;
  cout << "Enter two double values separated by a space: ";
  cin >> val1 >> val2;

  cout << "Values : " << val1 << ' ' << val2 << '\n';

  if (val1 < val2)
    cout << val1 << " is smaller and " << val2 << " is larger\n";
  else if (val2 < val1)
    cout << val2 << " is smaller and " << val1 << " is larger\n";
  else
    cout << val1 << " is equivalent to " << val2 << "\n";

  cout << "The sum of " << val1 << " and " << val2
       << " is " << val1 + val2 << '\n'

       << "The difference between " << val1 << " and " << val2
       << " is " << val1 - val2 << '\n'

       << "The product of " << val1 << " and " << val2
       << " is " << val1 * val2 << '\n';

  if (val2==0)
    cout << "Nice try haha! Unfortunately you can't divide by zero\n";
  else
    cout << "The ratio of " << val1 << " and " << val2
         << " is " << val1 / val2 << '\n';
}
