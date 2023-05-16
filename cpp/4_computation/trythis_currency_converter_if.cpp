#include "std_lib_facilities.h"

// convert from yen/euros/pounds to dollars
// a suffix 'y', 'e', 'p' indicates the unit of the input
// any other suffix is an error
int main()
{
    // Data taken from XE on 23 Apr, 11:00 PM GMT+7
    constexpr double yen_dollar_rate = 0.0075;
    constexpr double euro_dollar_rate = 1.11;
    constexpr double pound_dollar_rate = 1.24;

    double amount = 1;
    char currency = ' ';
    cout << "Please enter any amount of money followed by currency (y/e/p)\n";
    cin >> amount >> currency;

    if (currency == 'y')
        cout << "¥" << amount << " == $" << amount*yen_dollar_rate << '\n';
    else if (currency == 'e')
        cout << "€" << amount << " == $" << amount*euro_dollar_rate << '\n';
    else if (currency == 'p')
        cout << "£" << amount << " == $" << amount*pound_dollar_rate << '\n';
    else
        cout << "Sorry, I don't recognize a currency called '"
             << currency << "'\n";
}
