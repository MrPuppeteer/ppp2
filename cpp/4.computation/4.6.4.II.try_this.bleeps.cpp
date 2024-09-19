#include "std_lib_facilities.h"

int main()
{
  vector<string> bleeps = {"Broccoli", "Fish", "Bacon", "Dog"};
  for (string word; cin >> word;)
  {
    bool isBleep = false;
    for (string bleep : bleeps)
      if (word == bleep)
      {
        isBleep = true;
        break;
      }

    isBleep ? cout << "BLEEP\n" : cout << word << '\n';
  }
}
