#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector <ll> stak;

int main() {
    ll n;
    ll m;
    
    ll temp;

    ll previous = 0;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> temp;
        temp = previous + temp;
        stak.push_back(temp);
        previous = temp;
    }

    cin >> m;
    for (ll i = 0; i < m; i++) {
        cin >> temp;
        //cout << temp;

        auto it = lower_bound(stak.begin(), stak.end(), temp);

        cout << it - stak.begin() + 1 << '\n';
    }

    // for (ll i = 0; i < n; i++) {
    //     cout << stak[i] << ' ';
    // }

    // cout << '\n';
}