#include "std_lib_facilities.h"

int main()
{
  cout << "Write an operation followed by two operands:\n";
  string op;
  double a, b;
  cin >> op >> a >> b;

  if (op == "+" || op == "plus")
    cout << a << " + " << b << " = " << a + b << '\n';
  else if (op == "-" || op == "minus")
    cout << a << " - " << b << " = " << a - b << '\n';
  else if (op == "*" || op == "mul")
    cout << a << " * " << b << " = " << a * b << '\n';
  else if (op == "/" || op == "div")
    cout << a << " / " << b << " = " << a / b << '\n';
  else
    cout << "Unknown operation\n";
}
