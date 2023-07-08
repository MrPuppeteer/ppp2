#include "std_lib_facilities.h"

void print(const string& label, const vector<double>& v)
{
  cout << label << ": { ";
  for (double i : v)
    cout << i << ' ';
  cout << "}\n";
}

double maxv(const vector<double>& v)
{
  double max {v[0]};
  for (double d : v)
    if (d > max)
      max = d;
  return max;
}

int main()
try {
  vector<double> test {-5, 0, 6.7, -1000, 10.1e5, 10e5};
  
  print("Test data", test);
  cout << "Largest element from data: " << maxv(test) << '\n';
 
  return 0;
}
catch (exception& e)
{
  cerr << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Unknown exception!!\n";
  return 2;
}
