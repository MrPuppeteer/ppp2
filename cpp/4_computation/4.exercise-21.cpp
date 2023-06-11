#include "std_lib_facilities.h"

bool check_name(string name, vector<string> names)
{
  for (string n : names)
  {
    if (name == n)
      return true;
  }
  return false;
}

vector<int> find_score(int score, vector<int> scores)
{
  vector<int> res;
  for (auto i = 0; i < scores.size(); ++i)
  {
    if (score == scores[i])
      res.push_back(i);
  }
  if (res.size() == 0)
    res.push_back(-1);
  return res;
}

int main()
{
  vector<string> names;
  vector<int> scores;
  string name;
  int score;
  while (cin >> name >> score)
  {
    if (name == "NoName" && score == 0)
      break;
    if (check_name(name, names))
    {
      cout << "Error: Name '" << name << "' is entered twice!\n";
      continue;
    }
    names.push_back(name);
    scores.push_back(score);
  }

  cout << "Enter a score to output all the corresponding name with that score:\n";
  while (cin >> score)
  {
    vector<int> indexes = find_score(score, scores);
    if (indexes[0] == -1)
    {
      cout << "score not found\n";
      continue;
    }
    for (int i : indexes)
    {
      cout << names[i] << ' ';
    }
    cout << '\n';
  }
}
