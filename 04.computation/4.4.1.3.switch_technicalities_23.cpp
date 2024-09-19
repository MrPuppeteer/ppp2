#include "std_lib_facilities.h"

int main() {    // case labels must be constants
  // define alternatives:
  int y = 'y';  // this is going to cause trouble
  constexpr char n = 'n';
  constexpr char m = '?';
  cout << "Do you like fish?\n";
  char a;
  cin >> a;
  switch (a) {
    case n:
      // ...
      break;
    case y:     // error: variable in case label
      // ...
      break;
    case 'n':   // error: duplicate case label (n's value is 'n')
      // ...
      break;
    default:
      // ...
      break;
  }
}
