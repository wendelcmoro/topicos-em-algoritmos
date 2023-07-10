#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> sieve (1e7+15, true);

ll powerOfTwo(ll n) {
    ll val = 0;
    ll pot = 2;

    for (ll pot = 2; pot <=n;) {
        val += n/pot;

        pot = pot*2;
    }

    return val;
}

void eratosthenes(ll n) {
    sieve[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (ll j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    ll a;
    ll b;

    cin >> a;
    cin >> b;

    if (a == b) {
        cout << "?\n";
    }
    else {
        ll interval = abs(a - b);
        ll minimum = min(a, b);
        ll maximum = max(a, b);

        eratosthenes(maximum);

        ll primes = 0;

        for (ll i = minimum; i <= maximum; i++) {
            if (sieve[i]) {
                primes++;
            }
        }

        ll a = primes + interval - 1;
        ll b = interval;
        ll c = primes - 1;
        ll ea = powerOfTwo(a);
        ll eb = powerOfTwo(b);
        ll ec = powerOfTwo(c);

        if (ea - eb - ec > 0) {
            cout << "Bob\n";
        }
        else {
            cout << "Alice\n";
        }


    }
    

}