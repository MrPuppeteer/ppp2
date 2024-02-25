#include "std_lib_facilities.h"

void input_coins(int &coins, string coin_name)
{
  cout << "How many " << coin_name << " do you have: ";
  cin >> coins;
}

void print_coins(int coins, string coin_singular, string coin_plural = "")
{
  if (coins == 0)
    return;
  
  coin_plural = (coin_plural == "") ? coin_singular + "s" : coin_plural;

  cout << "You have " << coins << ' '
       << ((coins == 1) ? coin_singular : coin_plural)
       << ".\n";
}

int main()
{
  int pennies, nickels, dimes, quarters, half_dollars, one_dollars;

  input_coins(pennies, "pennies");
  input_coins(nickels, "nickels");
  input_coins(dimes, "dimes");
  input_coins(quarters, "quarters");
  input_coins(half_dollars, "half dollars");
  input_coins(one_dollars, "one-dollar coins");

  int total = pennies + nickels * 5 + dimes * 10 + quarters * 25
            + half_dollars * 50 + one_dollars * 100;

  cout << "\n\n";

  print_coins(pennies, "penny", "pennies");
  print_coins(nickels, "nickel");
  print_coins(dimes, "dime");
  print_coins(quarters, "quarter");
  print_coins(half_dollars, "half dollar");
  print_coins(one_dollars, "dollar");

  cout << "The value of all of your coins is $" << (double)total / 100
       << " (" << total << " cent"
       << ((total == 1) ? "" : "s")
       << ").\n";
}
