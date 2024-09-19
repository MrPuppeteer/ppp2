#include "std_lib_facilities.h"

void print_chars_with_val(char start, char stop) {
  // automatic switch to descending order if start is larger than stop
  if (start > stop) {
    for (char i = start; i >= stop; --i)
      cout << i << '\t' << int(i) << '\n';
  } else {
    for (char i = start; i <= stop; ++i)
      cout << i << '\t' << int(i) << '\n';
  }
  cout << '\n';
}

// calculate and print a table of characters with their coresponding integer values
int main() {
  // lowercase
  print_chars_with_val('a', 'z');

  // uppercase
  print_chars_with_val('A', 'Z');

  // digits
  print_chars_with_val('0', '9');
}
