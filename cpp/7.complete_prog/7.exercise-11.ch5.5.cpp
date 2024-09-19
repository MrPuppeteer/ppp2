#include "std_lib_facilities.h"

const char celsius {'C'};
const char kelvin {'K'};
const double absolute_zero {-273.15};
const string prompt {": "};
const char quit {'q'};

double ctok(double c) // converts Celsius to Kelvin
{
  if (c < absolute_zero)
    error("the temperature is below absolute zero!");
  return c - absolute_zero;
}

double ktoc(double k) // converts Kelvin to Celcius
{
  if (k < 0)
    error("the temperature is below absolute zero!");
  return k + absolute_zero;
}

bool user_quits()
{
  char tmp;
  cin >> tmp;
  if (tmp != quit) {
    cin.putback(tmp);
    return false;
  }
  return true;
}

void convert()
try
{
  cout << prompt;
  if (user_quits()) {
    cin.setstate(cin.eofbit);
    return;
  }
  double degrees;
  double res;
  char unit;
  if (cin >> degrees >> unit) {
    switch (unit) {
    case celsius:
      res = ctok(degrees);
      cout << degrees << " °C is equivalent to " << res << "K\n";
      break;
    case kelvin:
      res = ktoc(degrees);
      cout << degrees << " K is equivalent to " << res << " °C\n";
      break;
    default:
      error("unrecognized temperature unit.");
    }
  }
  else {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    error("bad input format.");
  }
}
catch (exception& e)
{
  cout << "Error: " << e.what() << '\n';
}

int main()
try
{
  cout << "Insert a temperature in Celcius or Kelvin to convert.\n"
       << "Format: Number followed by Unit\n"
       << "        Unit C for Celcius and K for Kelvin.\n"
       << "Insert q to exit the program\n";
  while (!cin.eof())
    convert();
  if (cin.eof())
    cout << "Bye, bye!\n";
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
