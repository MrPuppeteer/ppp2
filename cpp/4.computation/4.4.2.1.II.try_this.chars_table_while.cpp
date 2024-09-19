#include "std_lib_facilities.h"

int main()
{
  char i = 'a';
  while (i <= 'z')
  {
    cout << i << '\t' << (int)i << '\n';
    ++i;
  }
}
