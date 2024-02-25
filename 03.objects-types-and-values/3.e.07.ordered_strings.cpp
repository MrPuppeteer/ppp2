#include "std_lib_facilities.h"

// Print three string values in order
int main()
{
  string val1 = "";
  string val2 = "";
  string val3 = "";
  cout << "Enter three string values separated by a space: ";
  cin >> val1 >> val2 >> val3;

  if (val1 <= val2 && val1 <= val3) {
    if (val3 <= val2) {
      swap(val2, val3);
    }
  }
  else if (val2 <= val1 && val2 <= val3) {
    swap(val1, val2);
    if (val3 <= val2) {
      swap(val2, val3);
    }
  }
  else {
    swap(val1, val3);
    if (val3 <= val2) {
      swap(val2, val3);
    }
  }

  cout << "Values sorted : " << val1 << ", " << val2 << ", " << val3 << '\n';
}
