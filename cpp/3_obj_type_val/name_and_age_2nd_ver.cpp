#include "std_lib_facilities.h"

// read name and age (2nd version)
int main()
{
    cout << "Please enter your first name and age\n";
    string first_name = "???";	// string variable
                                // ("???" means "don't know the name")
    int age = -1;				// integer variable
    cin >> first_name >> age;	// read a string followed by an integer
    cout << "Hello, " << first_name << " (age " << age << ")\n";
}
