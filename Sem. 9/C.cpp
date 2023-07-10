#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    ll m;
    cin >> n;
    cin >> m;

    ll a;
    ll b;

    for (ll i = 0; i < m; i++) {
        cin >> a;
        cin >> b;
    }

    if (m == n - 1) {
        cout << "taca hld" << '\n';
    }
    else {
        cout << "acho que nao" << '\n';
    }
}