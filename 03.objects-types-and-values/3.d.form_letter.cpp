// simple form letter based on user input
#include "std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
  string first_name;  // first_name is a variable of type string
  cin >> first_name;  // read characters into first_name

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

  cout << "\n\nDear " << first_name << ",\n"
       << "  How are you? I am fine. I miss you.\n\n"
       << "Have you seen " << friend_name << " lately?\n"
       << "If you see " << friend_name << " please ask "
       << ((friend_sex == 'm') ? "him" : "her")
       << " to call me.\n"
       << ((age < 12) ? "Next year you will be " + to_string(age + 1) + ".\n" :
           (age == 17) ? "Next year you will be able to vote.\n" :
           (age > 70) ? "I hope you are enjoying retirement.\n" : "")
       << "Your sincerely,\n\n"
       << "Bagas N\n";
}
