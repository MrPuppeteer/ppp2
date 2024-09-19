#include "std_lib_facilities.h"

void print(const string& label, const vector<string>& v);

// Returns a new vector in reverse
vector<string> reverse_cr(const vector<string>& v)
{
  vector<string> rev;
  for (auto i = v.size(); i > 0; --i)
    rev.push_back(v[i-1]);
  return rev;
}

// Reverse vector
void reverse_r(vector<string>& v)
{
  auto limit {v.size() / 2};
  auto last {v.size() - 1};

  for (auto i = 0; i < limit; ++i)
    swap(v[i], v[last - i]);
}

int main()
try {
  vector<string> evenV {"one", "two", "three", "four"};
  print("Original even vector             ", evenV);
  vector<string> rev_evenV {reverse_cr(evenV)};
  print("Reverse even vector by const-ref ", rev_evenV);
  reverse_r(evenV);
  print("Reverse even vector by ref       ", evenV);

  vector<string> oddV {"one", "two", "three", "four", "five"};
  print("Original odd vector             ", oddV);
  vector<string> rev_oddV {reverse_cr(oddV)};
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

void print(const string& label, const vector<string>& v)
{
  cout << label << ": { ";
  for (string i : v)
    cout << i << ' ';
  cout << "}\n";
}
