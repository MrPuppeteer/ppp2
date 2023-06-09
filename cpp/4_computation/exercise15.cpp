#include "std_lib_facilities.h"

bool isPrime(int x, vector<int> primes)
{
  for (int p : primes)
  {
    if (x % p == 0)
      return false;
  }
  return true;
}

int main()
{
  vector<int> primes = {2};
  int n;
  cout << "How many number of primes do you want to find?\n";
  cin >> n;
  for (int i = 3; primes.size() < n; ++i)
  {
    if (isPrime(i, primes))
      primes.push_back(i);
  }
  cout << "The first " << n << " primes:\n";
  for (int p : primes)
  {
    cout << p << '\n';
  }
}
