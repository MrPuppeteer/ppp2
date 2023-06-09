#include "std_lib_facilities.h"

pair<int, int> find_mode(vector<int> numbers)
{
  unordered_map<int, int> hash;
  int n = numbers.size();
  for (int i = 0; i < n; i++)
    hash[numbers[i]]++;

  pair<int, int> res;
  res.first = -1;
  res.second = 0; // max
  for (auto i : hash)
  {
    if (res.second < i.second)
    {
      res.first = i.first;
      res.second = i.second;
    }
  }

  return res;
}

int main()
{
  vector<int> numbers;
  int n;
  cout << "Insert a series of numbers:\n";
  while (cin >> n)
    numbers.push_back(n);

  if (numbers.size() == 0)
  {
    cout << "No data inserted\n";
    return 1;
  }

  pair<int, int> res = find_mode(numbers);

  cout << "The mode of the series of numbers is " << res.first
       << " with " << res.second << " appearances.\n";
}
