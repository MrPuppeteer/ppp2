// convert from yen/euros/pounds/yuan/kroner to dollars
// a suffix 'y', 'e','p', 'c', or 'k' indicates the currency of the input
// any other suffix is an error
#include "std_lib_facilities.h"

int main() {
  // Data taken from XE on 9 Sep 2024, 11:00 PM GMT+7
  constexpr double yen_dollar_rate = 0.007;
  constexpr double euro_dollar_rate = 1.10;
  constexpr double pound_dollar_rate = 1.30;
  constexpr double yuan_dollar_rate = 0.14;
  constexpr double kroner_dollar_rate = 0.09;

  double amount = 1;
  char currency = ' ';
  cout << "Please enter any amount of money followed by currency (y/e/p/c/k)\n"
       << "y = yen, e = euro, p = pound, c = yuan, k = kroner\n";
  cin >> amount >> currency;

  switch (currency) {
    case 'y':
      cout << "JP¥" << amount << " == $" << amount*yen_dollar_rate << '\n';
      break;
    case 'e':
      cout << "€" << amount << " == $" << amount*euro_dollar_rate << '\n';
      break;
    case 'p':
      cout << "£" << amount << " == $" << amount*pound_dollar_rate << '\n';
      break;
    case 'c':
      cout << "CN¥" << amount << " == $" << amount*yuan_dollar_rate << '\n';
      break;
    case 'k':
      cout << "kr" << amount << " == $" << amount*kroner_dollar_rate << '\n';
      break;
    default:
      cout << "Sorry, I don't recognize a currency called'" << currency << "'\n";
      break;
  }
}
