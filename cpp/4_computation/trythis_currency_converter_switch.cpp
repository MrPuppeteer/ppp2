#include "std_lib_facilities.h"

// convert from yen/euros/pounds to dollars
// a suffix 'y', 'e', 'p', 'c', 'k' indicates the unit of the input
// any other suffix is an error
int main()
{
    // Data taken from XE on 23 Apr, 11:00 PM GMT+7
    constexpr double yen_dollar_rate = 0.0075;
    constexpr double euro_dollar_rate = 1.11;
    constexpr double pound_dollar_rate = 1.24;
    constexpr double yuan_dollar_rate = 0.15;
    constexpr double kroner_dollar_rate = 0.1;

    double amount = 1;
    char currency = ' ';
    cout << "Please enter any amount of money followed by currency (y/e/p/c/k)\n";
    cin >> amount >> currency;

    switch (currency) {
        case 'y':
        	cout << "JP¥" << amount << " == $"
                 << amount*yen_dollar_rate << '\n';
            break;
        case 'e':
        	cout << "€" << amount << " == $"
                 << amount*euro_dollar_rate << '\n';
            break;
        case 'p':
        	cout << "£" << amount << " == $"
                 << amount*pound_dollar_rate << '\n';
            break;
        case 'c':
            cout << "CN¥" << amount << " == $"
                 << amount*yuan_dollar_rate << '\n';
            break;
        case 'k':
        	cout << "kr" << amount << " == $"
                 << amount*kroner_dollar_rate << '\n';
            break;
        default:
        	cout << "Sorry, I don't recognize a currency called '"
                 << currency << "'\n";
            break;
    }
}
