#include "std_lib_facilities.h"

// Spelled-out numbers into digits
int main()
{
  cout << "Please enter an integer as a text string: ";
  string s;

  while (cin>>s) {
    int val = -1;
    if (s=="zero") val = 0;
    else if (s=="one") val = 1;
    else if (s=="two") val = 2;
    else if (s=="three") val = 3;
    else if (s=="four") val = 4;

    if (val >= 0)
      cout << s << " has the value of " << val << '\n';
    else
      cout << s << " is not a number I know\n";
    cout << "Please enter another integer as a text string: ";
  }
}
