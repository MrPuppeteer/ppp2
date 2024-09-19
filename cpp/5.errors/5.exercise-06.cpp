#include "std_lib_facilities.h"

double ctof(double c) // converts Celsius to Fahrenheit
{
  if (c == -273.15)
    error("the temperature cannot be below absolute zero!");
  double f = 9.0 / 5 * c + 32;
  return f;
}

double ftoc(double f) // converts Fahrenheit to Celcius
{
  if (f == -459.67)
    error("the temperature cannot be below absolute zero!");
  double c = (f - 32) * 5.0 / 9;
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
    cout << ctof(input) << "°F\n"; // convert and print out temperature
    break;
  case 'f':
  case 'F':
    cout << ftoc(input) << "°C\n"; // convert and print out temperature
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
