#include "std_lib_facilities.h"

vector<string> numbers = {
  "zero", "one", "two", "three", "four",
  "five", "six", "seven", "eight", "nine"
};

double get_number();
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);
void calculate(double x, double y, char op);

int main()
{
  double a, b;
  char op;
  cout << "Enter three arguments: "
       << "two operands (either written as digits or spelled out) "
       << "and an operator (+,-,*,/):\n";

  while (true)
  {
    a = get_number();
    if (a == -2)
      break;

    b = get_number();
    if (b == -2)
      break;

    cin >> op;
    if (op == '|')
      break;

    if (a == -1 || b == -1)
    {
      cout << "Please enter a single-digit number "
           << "either digits or spelled out!\n";
      continue;
    }

    calculate(a, b, op);
  }
}

double get_number()
{
  int num;
  string name;
  if (cin >> num)
  {
    if (num < 0 || num > 9)
      return -1;
    else
      return num;
  }
  else
  {
    cin.clear();
    cin >> name;

    if (name == "|")
      return -2;

    for (auto i = 0; i < numbers.size(); ++i)
      if (name == numbers[i])
        return i;

    return -1;
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
