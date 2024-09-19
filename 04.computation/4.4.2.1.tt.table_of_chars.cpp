#include "std_lib_facilities.h"

// calculate and print a table of characters with their coresponding integer values
int main() {
  char i = 'a';  // start from 'a'
  while (i<='z') {
    cout << i << '\t' << int(i) << '\n';
    ++i;      // increment i (that is i becomes i+1)
  }
}
