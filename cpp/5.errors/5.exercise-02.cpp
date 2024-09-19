#include "std_lib_facilities.h"

/* Error List:
 * 1. int k = c + 273.15;
 * 2. return int
 * 3. cin >> d;
 * 4. ctok("c");
 * 5. Cout
 * 6. '/n'
 */

double ctok(double c) // converts Celsius to Kelvin
{
  double k = c + 273.15;
  return k;
}

int main()
{
  double c = 0;       // declare input variable
  cin >> c;           // retrieve temperature to input variable
  double k = ctok(c); // convert temperature
  cout << k << '\n';  // print out temperature
}
