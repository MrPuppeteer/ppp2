#include "std_lib_facilities.h"

void input_coins(int &coins, string coin_name)
{
  cout << "How many " << coin_name << " do you have:\n";
  cin >> coins;
}

void print_coins(int coins, string coin_singular, string coin_plural = "")
{
  if (coins == 0)
    return;

  cout << "You have " << coins << ' ';
  if (coins == 1)
    cout << coin_singular;
  else
    coin_plural == "" ? cout << coin_singular + "s" : cout << coin_plural;
  cout << ".\n";
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

  int total = pennies + nickels * 5 + dimes * 10 + quarters * 25 + half_dollars * 50 + one_dollars * 100;

  print_coins(pennies, "penny", "pennies");
  print_coins(nickels, "nickel");
  print_coins(dimes, "dime");
  print_coins(quarters, "quarter");
  print_coins(half_dollars, "half dollar");
  print_coins(one_dollars, "dollar");

  cout << "The value of all of your coins is $" << (double)total / 100;
  if (total == 1)
    cout << " (" << total << " cent).\n";
  else
    cout << " (" << total << " cents).\n";
}
