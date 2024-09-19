#include "std_lib_facilities.h"

void print(const string& label, const vector<int>& v);
int check(int a, int b);
void fibonacci(int x, int y, vector<int>& v, int n);

// Returns a new vector in reverse
vector<int> reverse_cr(const vector<int>& v)
{
  vector<int> rev;
  for (auto i = v.size(); i > 0; --i)
    rev.push_back(v[i-1]);
  return rev;
}

// Reverse vector
void reverse_r(vector<int>& v)
{
  auto limit {v.size() / 2};
  auto last {v.size() - 1};

  for (auto i = 0; i < limit; ++i)
    swap(v[i], v[last - i]);
}

int main()
try {
  vector<int> evenV;
  fibonacci(1, 2, evenV, 8); // Generate even sized vector
  print("Original even vector             ", evenV);
  vector<int> rev_evenV {reverse_cr(evenV)};
  print("Reverse even vector by const-ref ", rev_evenV);
  reverse_r(evenV);
  print("Reverse even vector by ref       ", evenV);

  vector<int> oddV;
  fibonacci(1, 2, oddV, 7); // Generate odd sized vector
  print("Original odd vector             ", oddV);
  vector<int> rev_oddV {reverse_cr(oddV)};
  print("Reverse odd vector by const-ref ", rev_oddV);
  reverse_r(oddV);
  print("Reverse odd vector by ref       ", oddV);
  
  return 0;
}
catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "Unknown exception!\n";
  return 2;
}

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
