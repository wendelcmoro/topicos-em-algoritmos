#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    bool all_ones = true;
    ll res = 0;

    vector <ll> ans;

    ll c = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        res ^= x;

        if (x != 1) {
            all_ones = false;
        }

        if (x == 1) {
            c++;
        }

        ans.push_back(x);
    }

    if (all_ones) {
        res = (n % 2) == 0;
    }

    if (res == 0) {
        cout << "-1\n";
        return 0;
    }

    ll msb = (1 << __lg(res));
    for (ll i = 0; i < n; i++) {
        if (ans[i] & msb) {
            ll t = ans[i] ^ res;

            if (t == 0 && (c % 2) == 0 && c == (n - 1)) {
                t++;
            }

            if (t == 1 && ((c + 1) % 2) == 0 && (c + 1) == n) {
                t = 0;
            }

            cout << ans[i] - t << " " << i + 1 << "\n";
            break;
        }
    }
}