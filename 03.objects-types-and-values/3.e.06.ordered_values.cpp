#include "std_lib_facilities.h"

// Print three integers values in order
int main()
{
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  cout << "Enter three integer values separated by a space: ";
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
