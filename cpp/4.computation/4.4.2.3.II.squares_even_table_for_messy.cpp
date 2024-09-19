#include "std_lib_facilities.h"

int square(int x)
{
  return x * x;
}

int main()
{
  for (int i = 0; i < 100; i += 2)
  { // for i in the [0:100) range
    cout << i << '\t' << square(i) << '\n';
    ++i; // what's going on here? it smells like an error!
  }
}
