#include "std_lib_facilities.h"

int main()
{
    cout << "Enter an integer value:\n";
    int x;
    cin >> x;
    
    cout << "The value " << x << " is an ";
    if (x % 2 == 0)
        cout << "even";
    else
        cout << "odd";
    cout << " number\n";
}
