#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void factorize (ll n) {
    vector<pair<ll, ll>> factors;

    ll count = 0;
    for (ll i = 2; i * i <= n; i++) {
        count = 0;
        while (n % i == 0) {
            count ++;
            n /= i;
        }
        if (count > 0) {
            factors.push_back(pair(i, count));
        }
    }
    if (n > 1) {
        factors.push_back(pair(n, 1));
    }

    for (ll i = factors.size() - 1; i >= 0; i--) {
        cout << factors[i].first << ' ' << factors[i].second << '\n';
    }
    // cout << "\n";
}

int main() {
    ll t;
    cin >> t;

    ll k;
    ll p;
    ll e;

    ll mult;
    for (ll i = 0; i < t; i++) {
        cin >> k;
        for (ll j = 0; j < k; j++) {
            cin >> p;
            cin >> e;

            if (j > 0) {
                mult = mult*(pow(p, e));
            }
            else {
                mult = pow(p, e);
            }
        }
        // cout << "mult: " << mult - 1 << '\n';
        factorize(mult - 1);
    }

}