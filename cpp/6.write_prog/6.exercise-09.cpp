#include "std_lib_facilities.h"

static const vector<string> numbers = {"thousand", "hundred", "ten", "one"};

bool check(string input)
{
  if (input.length() > numbers.size())
  {
    cerr << "input is greater than maximum digits.\n";
    return false;
  }

  for (char c : input)
    if (c < '0' || c > '9')
    {
      cerr << "input is not an integer number.\n";
      return false;
    }

  return true;
}

vector<int> parse(string input)
{
  vector<int> p;

  for (char d : input)
  {
    if (p.size() != 0 || d != '0')
      p.push_back(d - '0');
  }

  if (p.size() == 0)
    p.push_back(0);

  return p;
}

int compose(vector<int> digits)
{
  int res = 0;
  for (int d : digits)
    res = res * 10 + d;
  return res;
}

int main()
try
{
  string input = "";
  vector<int> digits;
  int composed = 0;

  cout << "Insert " << numbers.size() << " or less digits integer to be composed.\n";

  while (cin >> input)
  {
    if (!check(input))
      continue;

    digits = parse(input);
    composed = compose(digits);

    cout << composed << " is ";
    for (int i = 0, idx = numbers.size() - digits.size();
         i < digits.size(); ++i, ++idx)
    {
      cout << digits[i] << ' ' << numbers[idx] << (digits[i] == 1 ? " " : "s ");
      if (idx < numbers.size() - 1)
        cout << "and ";
    }
    cout << '\n';
  }

  return 0;
}
catch (exception &e)
{
  cerr << "Error: " << e.what() << '\n';
  return 1;
}
catch (...)
{
  cerr << "Oops! unknown exception!\n";
  return 2;
}
