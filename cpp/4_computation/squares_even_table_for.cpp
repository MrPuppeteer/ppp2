#include "std_lib_facilities.h"

int square(int x)
{
    return x*x;
}

// calculate and print a table of squares of even numbers in the [0:100) range
int main()
{
    for (int i = 0; i<100; i+=2)
        cout << i << '\t' << square(i) << '\n';
}
