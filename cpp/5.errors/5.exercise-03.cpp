#include "std_lib_facilities.h"

double ctok(double c) // converts Celsius to Kelvin
{
  double k = c + 273.15;
  return k;
}

int main()
try
{
  double c = 0; // declare input variable
  cin >> c;     // retrieve temperature to input variable
  if (c < -273.15)
    error("the temperature cannot be below absolute zero!");
  double k = ctok(c); // convert temperature
  cout << k << '\n';  // print out temperature
  return 0;
}
catch (exception &e)
{
  cerr << "error: " << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Oops: unknown exception!\n";
  return 2;
}
