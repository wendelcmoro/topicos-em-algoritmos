#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;

    cin >> n;

    ll temp;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> temp;
        if (temp > 10) {
            sum += temp - 10;
        }
    }

    cout << sum << '\n';
}