#include "std_lib_facilities.h"

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);
void calculate(double x, double y, char op);

int main()
{
  double a, b;
  char op;
  cout << "Enter three arguments: two operands and an operator (+,-,*,/):\n";

  while (cin >> a >> b >> op)
  {
    calculate(a, b, op);
  }
}

double add(double x, double y)
{
  return x + y;
}

double sub(double x, double y)
{
  return x - y;
}

double mul(double x, double y)
{
  return x * y;
}

double div(double x, double y)
{
  return x / y;
}

void calculate(double x, double y, char op)
{
  switch (op)
  {
  case '+':
    cout << "The sum of " << x << " and " << y << " is "
         << add(x, y) << '\n';
    break;
  case '-':
    cout << "The difference between " << x << " and " << y << " is "
         << sub(x, y) << '\n';
    break;
  case '*':
    cout << "The product of " << x << " and " << y << " is "
         << mul(x, y) << '\n';
    break;
  case '/':
    if (y == 0)
      cout << "Error! Cannot divide by zero.\n";
    else
      cout << "The quotient of " << x << " and " << y << " is "
           << div(x, y) << '\n';
    break;
  default:
    cout << "Unrecognized operator!\n";
    break;
  }
}
