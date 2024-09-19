// convert from yen/euros/pounds to dollars
// a suffix 'y', 'e', or 'p' indicates the currency of the input
// any other suffix is an error
#include "std_lib_facilities.h"

int main() {
  // Data taken from XE on 9 Sep 2024, 11:00 PM GMT+7
  constexpr double yen_dollar_rate = 0.007;
  constexpr double euro_dollar_rate = 1.10;
  constexpr double pound_dollar_rate = 1.30;

  double amount = 1;
  char currency = ' ';
  cout << "Please enter any amount of money followed by currency (y/e/p)\n"
       << "y = yen, e = euro, p = pound\n";
  cin >> amount >> currency;

  if (currency == 'y')
    cout << "¥" << amount << " == $" << amount*yen_dollar_rate << '\n';
  else if (currency == 'e')
    cout << "€" << amount << " == $" << amount*euro_dollar_rate << '\n';
  else if (currency == 'p')
    cout << "£" << amount << " == $" << amount*pound_dollar_rate << '\n';
  else
    cout << "Sorry, I don't recognize a currency called'" << currency << "'\n";
}
