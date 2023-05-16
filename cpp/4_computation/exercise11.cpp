#include "std_lib_facilities.h"

bool isPrime(int x, vector<int> primes) {
    for (int p : primes) {
        if (x % p == 0) return false;
    }
    return true;
}

int main()
{
    vector<int> primes = {2};
    for (int i = 3; i <= 100; ++i) {
        if (isPrime(i, primes)) primes.push_back(i);
    }
    cout << "Primes between 1 and 100:\n";
    for (int p : primes) {
        cout << p << '\n';
    }
}
