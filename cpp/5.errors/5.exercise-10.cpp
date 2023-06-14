#include "std_lib_facilities.h"

double sum_of_N(int n, vector<double> values)
{
  if (n > values.size())
    error("you asked to sum more numbers than given values!");

  double sum = 0;
  for (int i = 0; i < n; ++i)
    sum += values[i];
  return sum;
}

vector<double> diffs_of_N(int n, vector<double> values)
{
  if (n > values.size())
    error("you asked to find more differences than given values!");
  if (n < 2)
    error("n must be 2 or greater to find differences");

  vector<double> diffs;
  for (int i = 0; i < n - 1; ++i)
    diffs.push_back(values[i + 1] - values[i]);
  return diffs;
}

int main()
try
{
  int n;
  cout << "Please enter the number of values you want to sum:\n";
  cin >> n;
  if (n < 1)
    error("the number of values must be 1 or greater!");
  else if (!cin)
    error("bad input!");

  double val;
  vector<double> values;
  cout << "Please enter some floating-point numbers (press '|' to stop):\n";
  while (cin >> val)
    values.push_back(val);

  cin.clear();
  char end = ' ';
  cin >> end;
  if (end != '|')
    error("bad input!");

  double sum = sum_of_N(n, values);
  cout << "The sum of the first " << n << " numbers ( ";
  for (int i = 0; i < n; ++i)
    cout << values[i] << " ";
  cout << ") is " << sum << ".\n";

  vector<double> diffs = diffs_of_N(n, values);
  cout << "The differences between adjacent values of the first "
       << n << " numbers are:\n";
  for (int i = 0; i < n - 1; ++i)
    cout << diffs[i] << ' ';
  cout << '\n';
  return 0;
}
catch (exception &e)
{
  cout << "error: " << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Oops: unknown exception!\n";
  return 2;
}
