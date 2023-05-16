#include "std_lib_facilities.h"

int square(int x)	// return the square of x
{
    return x*x;
}

int main()
{
    cout << square(2) << '\n';	// print 4
    cout << square(10) << '\n';	// print 100
}
