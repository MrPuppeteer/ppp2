#include "std_lib_facilities.h"

int square(int x)
{
    return x*x;
}

// calculate and print a table of squares 0-99
int main()
{
    for (int i = 0; i<100; ++i)
        cout << i << '\t' << square(i) << '\n';
}
