#include "std_lib_facilities.h"

class Name_value
{
public:
  string name;
  int value;
};

bool check_name(string name, vector<Name_value> pairs)
{
  for (Name_value n : pairs)
  {
    if (name == n.name)
      return true;
  }
  return false;
}

int main()
{
  vector<Name_value> pairs;
  string name;
  int value;

  while (cin >> name >> value)
  {
    if (name == "NoName" && value == 0)
      break;
    if (check_name(name, pairs))
    {
      cerr << "Error: Name '" << name << "' is entered twice!\n";
      continue;
    }
    pairs.push_back(Name_value{name, value});
  }
  cout << "Pairs entered:\n";
  for (auto i = 0; i < pairs.size(); ++i)
    cout << '(' << pairs[i].name << ',' << pairs[i].value << ")\n";
  return 0;
}
