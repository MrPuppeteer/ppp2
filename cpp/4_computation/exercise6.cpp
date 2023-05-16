#include "std_lib_facilities.h"

const vector<string> numbers = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};

int get_number(string number) {
    for (auto i = 0; i < numbers.size(); ++i) {
        if (number == numbers[i]) return i;
    }
    return -1;
}

int main()
{
    cout << "Enter a single-digit number to get spelled-out value\n"
         << "or enter the spelled-out number to get its digit form:\n";
    int n;
    string name;
    while (true) {
        if (cin >> n) {
            n < 0 || n > 10
                ? cout << "Please enter a single-digit number!\n"
                : cout << numbers[n] << '\n';
        }
        else {
            cin.clear();
        	cin >> name;
            if (name == "|")
            	break;
            int number = get_number(name);
            number == -1
                ? cout << "Not a spelled-out single-digit number!\n"
                : cout << number << '\n';
        }
    }
}
