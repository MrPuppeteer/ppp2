#include "std_lib_facilities.h"
#include "9.exercise-10.Chrono.h"

int main()
{
  constexpr int inc {5};

  for (int i = 1700; i < 2200; i += inc) {
    cout << i << ": ";
    if (Chrono::leapyear(i))
      cout << "LEAP year\n";
    else
      cout << "Common year\n";
  }

  return 0;
}
