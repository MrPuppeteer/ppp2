#include "std_lib_facilities.h"

struct Stats {
  double max {0};
  double min {0};
  double mean {0};
  double median {0};
};

void print(const string& label, const vector<double>& v)
{
  cout << label << ": { ";
  for (double i : v)
    cout << i << ' ';
  cout << "}\n";
}

void print_stats(const Stats& stats)
{
  cout << "Statistics:\n\tMax: " << stats.max << '\n'
       << "\tMin: " << stats.min << '\n'
       << "\tMean: " << stats.mean << '\n'
       << "\tMedian: " << stats.median << '\n';
}

double mean(const vector<double>& v)
{
  double sum {0};
  for (double d : v)
    sum += d;
  return sum / v.size();
}

double median(const vector<double>& v)
{
  if ((v.size() % 2) == 1)
    return v[v.size() / 2];
  size_t index {v.size() / 2};
  return (v[index - 1] + v[index]) / 2;
}

Stats get_stats(const vector<double>& v)
{
  vector<double> tmp {v};

  sort(tmp.begin(), tmp.end());
  Stats stats;
  stats.min = tmp[0];
  stats.max = tmp[tmp.size() - 1];
  stats.mean = mean(tmp);
  stats.median = median(tmp);

  return stats;
}

int main()
try {
  // Mean: 5.28571, Median: 6;
  vector<double> odd {3, 9, 1, 8, 7, 6, 3};
  // Mean: 4.75, Median: 4.5
  vector<double> even {4, 1, 9, 8, 5, 3, 2, 6};

  print("Odd (number of elements) data", odd);
  print_stats(get_stats(odd));
  cout << '\n';
 
  print("Even (number of elements) data", even);
  print_stats(get_stats(even));
  cout << '\n';

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
