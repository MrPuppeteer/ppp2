// run ./a.out 2> /dev/null to ignore error output
#include "std_lib_facilities.h"

void print(const string& label, const vector<int>& v)
{
  cout << label << ": { ";
  for (int i : v)
    cout << i << ' ';
  cout << "}\n";
}

// Perform overflow control to avoid undefined behavior before adding two int
int check(int a, int b)
{
  if (((b > 0) && (a > (numeric_limits<int>::max() - b))) ||
      ((b < 0) && (a < (numeric_limits<int>::min() - b))))
    error("integer overflows.");
  
  return a+b;
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
  if (v.size() != 0)
    error("Non empty vector passed as argument.");
  if (n < 2)
    error("n must be at least 2.");

  v.push_back(x);
  v.push_back(y);
  
  try {
  for (int i = 2; i < n; ++i)
    v.push_back(check(v[i-2], v[i-1]));
  }
  catch (exception& e) {
    cerr << e.what() << '\n';
  }
}

void test()
{
  vector<int> v;

  fibonacci(1, 2, v, 10);
  print("Test Fib(10)", v);

  v.clear();
  fibonacci(-2, -2, v, 10);
  print("Test with negatives", v);

  v.clear();
  fibonacci(1, 2, v, 20);
  print("Test Fib(20)", v);

  v.clear();
  fibonacci(-5, 4, v, 20);
  print("Test with positive and negative", v);

  v.clear();
  // Causes integer overflow
  fibonacci(1, 2, v, 50);
  print("Test Fib(50)", v);
}

void find_max()
{
  vector<int> v;
  int max{0};
  int min{0};
  int begin{-200};
  int end{200};
  int seq_size{50};

  for (int i = begin; i < end; ++i) {
    fibonacci(i, i+1, v, seq_size);
    int& val = v[v.size() - 1];
    if (val > max) max = val;
    if (val < min) min = val;
    v.clear();
  }

  cout << "Maximum integer approximate: " << max;
  cout << " (real limit " << numeric_limits<int>::max() << ")\n";
  cout << "Minimum integer approximate: " << min;
  cout << " (real limit " << numeric_limits<int>::min() << ")\n";
}

int main()
try {
  cout << "Test fibonaccion() function:\n";
  test();
  cout << "\n\nFind an approximation of maximum and minimum number\n";
  find_max();

  return 0;
}
catch (exception& e)
{
  cerr << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Unknown exception!\n";
  return 2;
}
