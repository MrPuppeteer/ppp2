#include "std_lib_facilities.h"

int main()
{
  vector<double> values;
  double sum = 0;
  double small = numeric_limits<double>::max();
  double large = numeric_limits<double>::min();
  for (double val; cin >> val;)
  {
    if (val < small)
      small = val;

    if (val > large)
      large = val;

    sum += val;
    values.push_back(val);
  }

  cout << "the total distance: " << sum << '\n'
       << "the smallest distance between two neightboring cities: "
       << small << '\n'
       << "the greatest distance between two neightboring cities: "
       << large << '\n'
       << "the mean distance between two neightboring cities: "
       << sum / values.size() << '\n';
}
