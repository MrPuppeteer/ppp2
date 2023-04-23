#include "std_lib_facilities.h"

void swap(string &x, string &y)
{
    string temp = x;
    x = y;
    y = temp;
}

int main()
{
    cout << "Enter three string values:\n";
    string str[3];
    cin >> str[0] >> str[1] >> str[2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2 - i; j++)
            if (str[j] > str[j+1])
                swap(str[j], str[j+1]);
    cout << str[0] << ", " << str[1] << ", " << str[2] << '\n';
}
