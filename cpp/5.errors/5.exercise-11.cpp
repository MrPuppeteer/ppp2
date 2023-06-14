#include "std_lib_facilities.h"

// The largest Fibonacci number that fits in an int is 1836311903 (46th)
int main()
try
{
  int n;
  cout << "Please enter the number of values of the Fibonacci series:\n";
  cin >> n;
  if (!cin)
    error("bad input!");
  if (n < 1)
    error("the number of values must be 1 or greater!");

  pair<int, int> prev;
  int fib;
  prev.first = 1;
  prev.second = 1;
  cout << "The first " << n << " Fibonacci numbers are:\n";
  if (n >= 1)
    cout << 1 << ' ';
  if (n >= 2)
    cout << 1 << ' ';
  for (int i = 2; i < n; ++i)
  {
    fib = prev.first + prev.second;
    if (fib < prev.first)
      error("the next value cannot be represented as an int");
    cout << fib << ' ';
    prev.second = prev.first;
    prev.first = fib;
  }
  cout << '\n';
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
