#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N = 1000000001;
vector <ll> a(N, 0);

vector <ll> b(1000000000, 0);
vector <ll> c(1000000000, 0);

void add(ll i, ll delta) {
    for (; i < N; i += i & (-i)) {
        a[i] += delta;
    }
}

ll get(ll i) {
    ll ans = 0;
    for (; i > 0; i -= i & (-i)) {
        ans += a[i];
    }
    return ans;
}

int main() {
    ll n;
    ll h;

    cin >> n;
    cin >> h;

    ll temp;

    ll aux = 0;

    for (ll i = 1; i <= n; i++) {
        cin >> temp;
        add(temp, 1);
        if (i > h) {
            aux += get(n) - get(temp);
        }
    }
    

    cout << aux << '\n';
}


