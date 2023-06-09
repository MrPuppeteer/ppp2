/* This program outputs the message
 * "Hello, programming!
 *  Here we go!" to the monitor
 */

#include "std_lib_facilities.h"

int main() // C++ programs start by executing the function main
{
  cout << "Hello, programming!\n"; // output "Hello, programming!"
  cout << "Here we go!\n";         // output "Here we go!"
  keep_window_open();              // wait for a character to be entered
  return 0;
}
