#include "std_lib_facilities.h"

// compute mean and median temperatures
int main()
{
  vector<double> temps;           // temperatures
  for (double temp; cin >> temp;) // read into temp
    temps.push_back(temp);        // put temp into vector

  auto size = temps.size();

  // compute mean temperature:
  double sum = 0;
  for (int x : temps)
    sum += x;
  cout << "Average temperature: " << sum / size << '\n';

  // compute median temperature:
  sort(temps); // sort temperature
  cout << "Median temperature: ";
  size % 2 == 0
      ? cout << (temps[size / 2] + temps[(size / 2) - 1]) / 2 << '\n'
      : cout << temps[size / 2] << '\n';
}
