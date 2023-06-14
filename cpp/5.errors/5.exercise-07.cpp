#include "std_lib_facilities.h"

pair<double, double> quad_eq(double a, double b, double c)
{
  if (a == 0)
    error("the equation is not a quadratic equation (a = 0)");

  double d = b * b - 4 * a * c;
  if (d < 0)
    error("the equation has no real roots");

  pair<double, double> x;
  x.first = (-b + sqrt(d)) / (2 * a);
  x.second = (-b - sqrt(d)) / (2 * a);

  return x;
}

int main()
try
{
  double a = 0;
  double b = 0;
  double c = 0;

  cout << "Insert coefficient a, b, and c to solve quadratic equations "
       << "ax^2 + bx + c = 0\n";
  cin >> a >> b >> c;
  if (!cin)
    error("bad input!");

  pair<double, double> x = quad_eq(a, b, c);

  cout << "The roots of quadratic equation " << a << "x^2";
  b > 0 ? cout << " + " << b : cout << " - " << -b;
  c > 0 ? cout << " + " << c : cout << " - " << -c;
  cout << " = 0 is\n"
       << "x1 = " << x.first << " or "
       << "x2 = " << x.second << '\n';

  return 0;
}
catch (exception &e)
{
  cout << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Oops: unknown exception!\n";
  return 2;
}
