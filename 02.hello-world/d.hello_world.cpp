// no #include here

// misspelled
// #include "std_facilities.h"

#include "std_lib_facilities.h"

// use abbreviation int in C++ for integer type
// integer main()
// main function must use int type #5
// double main()
int main() // C++ programs start by executing the function main 
{
  // enclosed/terminate string with "
  // cout << "Hello, World!\n;
  // output operator is << while < is less-than operator
  // cout < "Hello, World!\n";
  // use double quotes for string and single for char
  // cout << 'Hello, World!\n';
  // terminate output statement with semicolon;
  // cout << "Hello, World!\n"
  // C++ is case-sensitive #1
  // COUT << "hELLO, wORLD!\N";
  /* comma returns a value which is always the 2nd (right) argument
   * while a semicolon just ends statements #2
   * https://stackoverflow.com/questions/2087026/effect-of-using-a-comma-instead-of-a-semi-colon-in-c-and-c */
  // cout << "Hello, World!\n",
  // use cout to output characters and cin to input #3
  // cin << "Hello, World!\n";
  // slight typo #4
  // cout << "Hell, World!\n";
  cout << "Hello, World!\n";  // output "Hello, World!"
  keep_window_open();         // wait for a character to be entered
  return 0;
}
