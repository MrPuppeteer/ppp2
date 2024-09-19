#include "std_lib_facilities.h"

int main()
{
  double sum = 0;
  // source https://coolcosmos.ipac.caltech.edu/ask/63-What-are-the-highest-and-lowest-temperatures-on-Earth
  double high_temp = -126; // initialize to lowest
  double low_temp = 136;   // initialize to highest
  int no_of_temps = 0;

  for (double temp; cin >> temp;) // read temp
  {
    ++no_of_temps; // count temperatures
    sum += temp;   // compute sum
    if (temp > high_temp)
      high_temp = temp; // find high
    if (temp < low_temp)
      low_temp = temp; // find low
  }

  cout << "High temperature: " << high_temp << '\n';
  cout << "Low temperature: " << low_temp << '\n';
  cout << "Average temperature: " << sum / no_of_temps << '\n';
}
