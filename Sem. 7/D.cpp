#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> sieve (1e7+15, true);

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
    ll n;
    cin >> n;

    eratosthenes(n);

    ll p1;
    ll p2;
    ll count = 0;

    for (ll i = 2; i <= n/2; i++) {
        if (sieve[i] && sieve[n - i]) {
            // cout << i << ' ' << n - i << '\n';
            count++;
        }
    }
    
    cout << count << '\n';
}
