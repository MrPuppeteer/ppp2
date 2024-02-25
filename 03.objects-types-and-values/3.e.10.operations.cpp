#include "std_lib_facilities.h"

// Calculator
int main()
{
  cout << "Please enter an operation (+, -, *, /, plus, minus, mul, div) "
       << "followed by two floating-point values separated by a space: ";
  string op;
  double x = 0;
  double y = 0;
  while (cin >> op >> x >> y) {
    double res = 0;
    if (op == "+" || op == "plus") res = x+y;
    else if (op == "-" || op == "minus") res = x-y;
    else if (op == "*" || op == "mul") res = x*y;
    else if (op == "/" || op == "div") {
      if (y==0) {
        cout << "Nice try! Unfortunately can't divide by zero\n";
        cout << "Please try again: ";
        continue;
      }
      res = x/y;
    }
    else {
      cout << "Unknown operation\n";
      cout << "Please try again: ";
      continue;
    }
    
    cout << x << op << y << " == " << res << '\n';
    cout << "Please try again: ";
  }
}
