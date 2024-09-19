#include "std_lib_facilities.h"

int main()
try
{
  vector<int> v; // a vector of ints
  for (int i; cin >> i;)
    v.push_back(i);                   // get values
  for (int i = 0; i <= v.size(); ++i) // print values
    cout << "v[" << i << "] == " << v[i] << '\n';
}
catch (out_of_range)
{
  cerr << "Oops! Range error\n";
  return 1;
}
catch (...)
{ // catch all other exceptions
  cerr << "Exception: something went wrong\n";
  return 2;
}
