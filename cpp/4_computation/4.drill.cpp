#include "std_lib_facilities.h"

int main()
{
  double val;
  string unit;
  vector<double> values;
  double sum = 0;
  double small = numeric_limits<double>::max();
  double large = numeric_limits<double>::min();

  while (cin >> val >> unit)
  {
    if (unit == "cm")
      values.push_back(val / 100);
    else if (unit == "m")
      values.push_back(val);
    else if (unit == "in")
      values.push_back(val * 2.54 / 100);
    else if (unit == "ft")
      values.push_back(val * 12 * 2.54 / 100);
    else
    {
      cout << "Illegal unit!\n";
      continue;
    }

    double last = values.back();

    sum += last;

    if (last < small)
    {
      small = last;
      cout << "the smallest value so far: " << small << "m\n";
    }

    if (last > large)
    {
      large = last;
      cout << "the largest value so far: " << large << "m\n";
    }
  }

  cout << "the smallest: " << small << 'm'
       << "\nthe largest: " << large << 'm'
       << "\nthe number of values: " << values.size()
       << "\nthe sum of values: " << sum << '\n';

  sort(values);

  cout << "values: \n";
  for (double value : values)
    cout << '\t' << value << "m\n";
}
