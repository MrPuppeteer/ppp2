// read name and age (trythis version)
#include "std_lib_facilities.h"
int main()
{
  cout << "Please enter your first name and age\n";
  string first_name = "???";  // string variable
                              // ("???" means "don't know the name")
  double age = -1;               // integer variable (-1 means "don't know the age")
  cin >> first_name >> age;   // read a string followed by an integer
  cout << "Hello, " << first_name << " (age " << age * 12 << " month(s))\n";
}