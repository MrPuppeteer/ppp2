#include "std_lib_facilities.h"

vector<int> sieve_of_eratosthenes(int n) {
    vector<int> a(n+1, 1);

    for (int i = 2; i*i <= n; i++) {
        if (a[i] == 1)
            for (int j = i*i; j <= n; j += i)
                a[j] = 0;
    }

    return a;
}

int main()
{
    int limit;
    cout << "Enter max value:\n";
    cin >> limit;
    vector<int> primes = sieve_of_eratosthenes(limit);
    cout << "Primes between 1 and " << limit << ":\n";
    for (int i = 2; i <= limit; i++) {
        if (primes[i] == 1) cout << i << '\n';
    }
}
