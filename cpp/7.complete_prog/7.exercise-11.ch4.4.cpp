#include "std_lib_facilities.h"

const char yes {'y'};
const char no {'n'};
const char is_more {'M'};
const char is_less {'L'};

int first {1};
int last {100};
int candidate {0};
int question {0};

void checked_modify_range(int f, int l)
{
  if ((f > l) || (f < first) || (l > last)) {
    error("you LIED!");
  }

  first = f;
  last = l;
}

void guess()
{
  candidate = (first+last)/2;
  char guess_type;
  if (question%2 == 0) guess_type = is_less;
  else guess_type = is_more;

  cout << "Is your number "
       << (guess_type == is_less ? "less" : "more")
       << " than " << candidate << "? (y/n)\n";

  char answer {' '};
  cin >> answer;
  if (answer == yes) {
    ++question;
    if (guess_type == is_less)
      checked_modify_range(first, candidate - 1);
    else if (guess_type == is_more)
      checked_modify_range(candidate + 1, last);
  }
  else if (answer == no) {
    ++question;
    if (guess_type == is_less) checked_modify_range(candidate, last);
    if (guess_type == is_more) checked_modify_range(first, candidate);
  }
  else {
    cout << "Sorry, I don't understand your answer. Try again...\n";
  }
}

void guess_one_from_two()
{
  cout << "Is the number you're thinking of the " << first << "? (y/n)\n";
  char answer {' '};
  cin >> answer;
  ++question;

  if (answer == yes)
    last = first;
  else if (answer == no)
    first = last;
  else {
    cout << "Sorry, I don't understand your answer. Try again...\n";
    --question;
  }
}

int main()
try {
  cout << "Think a number between " << first << " and " << last << ".\n"
       << "And I will ask questions to figure out what the number is.\n";
  while (first != last)
  {
    if (last-first == 1) guess_one_from_two();
    else guess();
  }
  cout << "The number is " << first << '\n';
  cout << "I only need " << question << " questions to guess.\n";
  return 0;
}
catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "unknown exception!\n";
  return 2;
}
