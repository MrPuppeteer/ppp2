#include "std_lib_facilities.h"

double ctok(double c) // converts Celsius to Kelvin
{
  if (c < -273.15)
    error("the temperature cannot be below absolute zero!");
  double k = c + 273.15;
  return k;
}

double ktoc(double k) // converts Kelvin to Celcius
{
  if (k < 0)
    error("the temperature cannot be below absolute zero!");
  double c = k - 273.15;
  return c;
}

int main()
try
{
  double input = 0; // declare input variable
  char unit = 'c';
  cin >> input >> unit; // retrieve temperature to input variable
  switch (unit)
  {
  case 'c':
  case 'C':
    cout << ctok(input) << "K\n"; // convert and print out temperature
    break;
  case 'k':
  case 'K':
    cout << ktoc(input) << "°C\n"; // convert and print out temperature
    break;
  default:
    error("unrecognized temperature unit!");
    break;
  }
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
