#include "std_lib_facilities.h"

void print(const vector<string>& v, const string& quit, const string& which)
{
  cout << "Printing vector { ";
  for (string s : v) cout << s << ' ';
  cout << "} UNTIL the " << which << " appearance of '" << quit << "' ...\n";
}

void print_until_s(const vector<string>& v, const string& quit)
{
  print(v, quit, "first");
  for (string s : v) {
    if (s == quit) return;
    cout << '\t' << s << '\n';
  }
}

void print_until_ss(const vector<string>& v, const string& quit)
{
  print(v, quit, "second");
  bool seen {false};
  for (string s : v) {
    if (s == quit) {
      if (seen)
        return;
      else
        seen = true;
    }
    cout << '\t' << s << '\n';
  }
}

int main()
try
{
  vector<string> test_data {"1", "2", "3", "4", "5"};
  const vector<string> test_data_c {};
  string exit {"exit"};
  string quit {"quit"};

  cout << "\nprint_until_s() tests:\n\n";
  print_until_s({"Hi!", "Hello", "Bye", "quit", "Until tomorrow"}, quit);
  print_until_s(test_data, "");
  print_until_s(test_data_c, exit);
  print_until_s({"quit", "Hello", "Bye", "quit", "Until tomorrow"}, quit);
  print_until_s({"Hi!", "Hello", "Bye", "quit", exit}, exit);

  cout << "\nprint_until_ss() tests:\n\n";
  print_until_ss({"Hi!", "Hello", "Bye", "quit", "Until tomorrow", "quit", 
                  "No more"}, quit);
  print_until_ss({"Hi!", "Hello", exit, "Bye", "exit", "quit", exit}, exit);
  
  return 0;
}
catch(exception& e)
{
  cerr << e.what() << '\n';
  return 1;
}
catch(...)
{
  cerr << "Unknown exception!\n";
  return 2;
}
