#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5+15;
#define NEUTRAL 100000000
#define FACTOR 1
#define OP(X, Y) min(X, Y)

const ll L = ceil(log2(N));
struct dlta { 
    ll add = 0, set = -1; 
};

vector<ll> t (2*N); vector<dlta> delta (2*N);

ll apply(ll ti, dlta d, ll sz) {
    if (d.set != -1) {
        t[ti] = d.set * FACTOR;
        delta[ti] = {0, d.set};
    }
    if (d.add != 0) {
        t[ti] += d.add * FACTOR;
        delta[ti].add += d.add;
    }
    return t[ti];
}

void pull(ll i) {
    for (ll s = __builtin_ctz(i) + 1; s < L; s++) {
        ll ti = i >> s;
        t[ti] = OP(t[2 * ti], t[2 * ti + 1]);
    }
}

void push(ll i) {
    ll sz = 1 << (L - 1);
    for (ll s = L; s > 0; s--, sz /= 2) {
        ll ti = i >> s;
        apply(2 * ti, delta[ti], sz);
        apply(2 * ti + 1, delta[ti], sz);
        delta[ti] = {};
    }
}

void apply_inclusive(ll l, ll r, char op = '\0', ll x = 0) {
    r++;
    dlta d;
    if (op == '+') {
        d.add = x;
    }
    if (op == '=') {
        d.set = x;
    }
    ll tl = l += N, tr = r += N, sz = 1;
    push(tl);
    push(tr);
    for (; l < r; l /= 2, r /= 2, sz *= 2) {
        if (l & 1) {
            apply(l++, d, sz);
        }
        if (r & 1) {
            apply(--r, d, sz);
        }
    }
    pull(tl);
    pull(tr);
}

void add_inclusive(ll l, ll r, ll d) {
    apply_inclusive(l, r, '+', d);
}

ll op_inclusive(int l, int r) {
    r++;
    int tl = l += N, tr = r += N, sz = 1;
    push(tl);
    push(tr);
    ll ans = NEUTRAL;
    for (; l < r; l /= 2, r /= 2, sz *= 2) {
        if (l & 1) {
            ans = OP(ans, apply(l++, dlta(), sz));
        }
        if (r & 1) {
            ans = OP(ans, apply(--r, dlta(), sz));
        }
    }
    pull(tl);
    pull(tr);
    return ans;
}

void build(vector<ll> &src) {
    for (ll i = 1; i < src.size(); i++)
        t[N + i] = src[i];
    for (ll ti = N - 1; ti > 0; ti--)
        t[ti] = OP(t[2 * ti], t[2 * ti + 1]);
}

int main() {
    ll n;
    ll q;

    cin >> n;
    cin >> q;

    vector <ll> el(n+1);

    ll temp;
    ll op;
    ll start;
    ll end;
    ll k;

    for (ll i = 1; i <= n; i++) {
        cin >> temp;
        el[i] = temp;
    }

    build(el);

    for (ll i = 0; i < q; i++) {
        cin >> op;
        cin >> start;
        cin >> end;
        if (op == 1) {
            cin >> k;
            add_inclusive(start, end, k);
        }
        else if (op == 2) {
            cout << op_inclusive(start, end) << "\n";
        }
    }

}