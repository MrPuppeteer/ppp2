#include "std_lib_facilities.h"

static const vector<string> verbs = {"rules", "fly", "swim"};
static const vector<string> nouns = {"birds", "fish", "C++"};
static const vector<string> conjunctions = {"and", "or", "but"};
static const vector<string> determiners = {"the"};

bool is_in(string s, vector<string> v)
{
  for (string vs : v)
    if (vs == s)
      return true;
  return false;
}

bool subject()
{
  string t;
  cin >> t;

  if (is_in(t, determiners))
  {
    cin >> t;
    if (is_in(t, nouns))
      return true;
  }
  if (is_in(t, nouns))
    return true;
  return false;
}

bool sentence()
{
  if (!subject())
    return false;
  string t;
  cin >> t;
  if (!is_in(t, verbs))
    return false;
  cin >> t;
  if (t == ".")
    return true;
  if (!is_in(t, conjunctions))
    return false;
  return sentence();
}

int main()
try
{
  char c;
  while (cin)
  {
    cin >> c;
    if (c == 'q')
      break;
    else
      cin.putback(c);
    cout << (sentence() ? "OK" : "Not OK") << '\n';
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
  cerr << "Oops! unknown exception\n";
  return 2;
}
