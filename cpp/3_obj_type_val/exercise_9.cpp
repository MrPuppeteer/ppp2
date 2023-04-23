#include "std_lib_facilities.h"

int main()
{
    cout << "Spell out a number:\n";
    string spell;
    vector<string> str = {"zero", "one", "two", "three", "four"};
    cin >> spell;
    for (auto i = 0; i < str.size(); i++)
        if (spell == str[i]) {
            cout << i << '\n';
            return 0;
        }
    
    cout << "not a number I know\n";
}
