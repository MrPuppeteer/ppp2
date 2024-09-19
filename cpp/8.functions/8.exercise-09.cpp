#include "std_lib_facilities.h"

double index(const vector<double>& u, const vector<double>& v)
{
  if (u.size() != v.size())
    error("vectors have different sizes.");

  double sum {0};
  size_t limit {u.size()};
  for (size_t i = 0; i < limit; ++i)
    sum += u[i] * v[i];
  return sum;
}

int main()
try {
  vector<double> weight {1, 2, 3};
  
  vector<double> price {1, 2, 3};
  cout << index(weight, price) << '\n';

  // Trigger error
  vector<double> price_err {1, 2};
  cout << index(weight, price_err) << '\n';
  return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}
