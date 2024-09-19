#include "std_lib_facilities.h"
#include <string>

const string stop {"stop"};

// Checks if string s is already present on vector v
bool check_duplicate(const vector<string>& v, const string& s)
{
  for (string x : v)
    if (x == s) return true;
  return false;
}

// Read max string n into vector names, no duplicate allowed
void get_names(vector<string>& names, string stop)
{
  cout << "Write people names (write stop when there's enough)...\n";
  while (true) {
    cout << ": ";
    string n;
    cin >> n;
    if (n == stop) return;
    while (check_duplicate(names, n)) {
      cout << "Duplicated name " << n << "! Try again...\n: ";
      cin >> n;
    }
    names.push_back(n);
  }
}

// Get ages for people in vector names.
void get_ages(const vector<string>& names, vector<double>& ages)
{
  cout << "Give me the ages of each person...\n";
  for (string name : names) {
    cout << "How old is " << name << "? ";
    double age {0};
    while (!(cin >> age)) {
      cout << "Sorry, I don't understand what you mean...\n"
           << "How old is " << name << "? ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    ages.push_back(age);
  }
}

void print_pairs(const vector<string>& names, const vector<double>& ages)
{
  size_t limit = names.size();
  for (size_t i = 0; i < limit; ++i)
    cout << "  " << names[i] << " is " << ages[i] << " years old.\n";
}

size_t find_idx_name(const vector<string>& names, const string& name)
{
  size_t limit = names.size();
  for (size_t i = 0; i < limit; ++i)
    if (names[i] == name)
      return i;
  error("No element found!");
  return -1;
}

void sort_pairs(vector<string>& names, vector<double>& ages)
{
  vector<string> og_names {names};
  vector<double> og_ages {ages};

  sort(names.begin(), names.end());
  size_t limit = names.size();
  for (size_t i = 0; i < limit; ++i)
    ages[i] = og_ages[find_idx_name(og_names, names[i])];
}

int main()
try {
  vector<string> names;
  vector<double> ages;
  
  get_names(names, stop);
  get_ages(names, ages);
 
  cout << "\nOK! So you tell me about these people:\n";
  print_pairs(names, ages);
 
  sort_pairs(names, ages);
  cout << "\nThat sorted by name are:\n";
  print_pairs(names, ages);
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
    cerr << "Unknown exception!\n";
    return 2;
}
