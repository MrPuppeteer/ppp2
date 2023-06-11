// Write a letter
#include "std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
  string first_name; // first_name is a variable of type string
  cin >> first_name; // read characters into first_name

  cout << "Enter the name of another friend:\n";
  string friend_name;
  cin >> friend_name;

  cout << "Enter friend's sex ('m' if male or 'f' if female):\n";
  char friend_sex;
  cin >> friend_sex;
  if (friend_sex != 'm' && friend_sex != 'f')
    simple_error("you're kidding!");

  cout << "Enter the age of the recipient:\n";
  int age;
  cin >> age;
  if (age <= 0 || age >= 110)
    simple_error("you're kidding!");

  cout << "\n\nDear " << first_name << ",\n\n"
       << "  How are you? I am fine. I miss you.\n"
       << "Have seen " << friend_name << " lately?\n"
       << "If you see " << friend_name << " please ask ";

  if (friend_sex == 'm')
    cout << "him";
  else if (friend_sex == 'f')
    cout << "her";
  cout << " to call me.\n";

  if (age < 12)
    cout << "Next year you will be " << age + 1 << ".\n";
  else if (age == 7)
    cout << "Next year you will be able to vote.\n";
  else if (age > 70)
    cout << "I hope you are enjoying retirement.\n";

  cout << "Your sincerely,\n\n";
  cout << "Bagas N\n";
}
