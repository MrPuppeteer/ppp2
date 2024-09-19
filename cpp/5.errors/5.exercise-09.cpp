#include "std_lib_facilities.h"

int sum_of_N(int n, vector<int> values)
{
  if (n > values.size())
    error("you asked to sum more numbers than given values!");

  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    int test = sum + values[i];
    if (values[i] >= 0 && test < sum)
      error("the result cannot be represented as an int");
    else if (values[i] < 0 && test > sum)
      error("the result cannot be represented as an int");
    sum += values[i];
  }
  return sum;
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

  int val;
  vector<int> values;
  cout << "Please enter some integers (press '|' to stop):\n";
  while (cin >> val)
    values.push_back(val);

  cin.clear();
  char end = ' ';
  cin >> end;
  if (end != '|')
    error("bad input!");

  int sum = sum_of_N(n, values);
  cout << "The sum of the first " << n << " numbers ( ";
  for (int i = 0; i < n; ++i)
    cout << values[i] << " ";
  cout << ") is " << sum << ".\n";
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
