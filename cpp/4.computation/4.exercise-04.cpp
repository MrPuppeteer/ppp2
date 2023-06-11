#include "std_lib_facilities.h"

int main()
{
  int min = 1;
  int max = 100;
  int q = 0;
  int guess;
  char ans = ' ';

  cout << "Think a number between 1 and 100 (exclusive).\n"
       << "And I will ask questions to figure out what the number is.\n";
  while (max - min > 1)
  {
    guess = (min + max) / 2;
    cout << "Is the number you are thinking of less than "
         << guess << "? (y/n)\n";
    cin >> ans;
    if (ans == 'y')
    {
      max = guess;
      q++;
    }
    else if (ans == 'n')
    {
      min = guess;
      q++;
    }
    else
      cout << "invalid answer!\n";
  }
  cout << "The number is " << (min + max) / 2 << '\n';
  cout << "I only need " << q << " questions to guess.\n";
}
