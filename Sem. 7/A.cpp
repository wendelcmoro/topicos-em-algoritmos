#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    ll g = extgcd(b, a % b, x, y);
    tie(x, y) = make_tuple(y, x - (a / b) * y);

    return g;
}

ll inv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);

    return ((x % m) + m) % m;
}

ll norm(ll a, ll b) {
    a %= b;
    return (a < 0) ? a + b : a;
}

pair<ll, ll> crtSingle(ll a, ll n, ll b, ll m) {
    ll x, y;
    ll g = extgcd(n, m, x, y);
    
    if ((a - b) % g) {
        return {-1, -1};
    }
    
    ll lcm = (m/g) * n;
    return { 
        norm(a + n*(x*(b-a)/g % (m/g)), lcm), lcm 
    };
}

ll crt(vll a, vll m, ll t) {
    ll ans = a[0];
    ll lcm = m[0];

    for (ll i = 1; i < t; i++) {
        tie(ans, lcm) = crtSingle(ans, lcm, a[i], m[i]);

        if (ans == -1) {
            return -1;
        }
    }

    return ans;
}

int main() {
    ll n;
    cin >> n;

    vll f(n);
    vll d(n);
    for (ll i = 0; i < n; i++) {
        cin >> f[i];
        cin >> d[i];
    }

    cout << crt(d, f, n) << '\n';
}