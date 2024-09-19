#include "std_lib_facilities.h"

void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

int main()
{
  cout << "Enter three integer values:\n";
  int num[3];
  cin >> num[0] >> num[1] >> num[2];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2 - i; j++)
      if (num[j] > num[j + 1])
        swap(num[j], num[j + 1]);
  cout << num[0] << ", " << num[1] << ", " << num[2] << '\n';
}
