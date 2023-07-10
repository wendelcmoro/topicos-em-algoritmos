#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N = 100001;
vector <ll> a(N, 0);
vector <ll> aux;

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

ll binSearch(ll val) {
    ll lo = 1;
    ll hi = N;
    while (lo != hi) {

        // cout << "imprimindo lo " << lo << endl;
        // cout << "imprimindo hi " << hi << endl;

        ll mi = lo + (hi - lo) / 2;

        if (get(mi) < val) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }

    }
    return lo;
}

int main() {
    ll n;
    ll q;

    cin >> n;
    cin >> q;

    ll input;
    
    for (ll i = 1; i <= n; i++) {
        cin >> input;
        add(i, 1);
        aux.push_back(input);
    }

    char op;
    ll cam = 1;
    for (ll i = 1; i <= q; i++) {
        cin >> op;

        if (op == 'm') {
            cin >> input;
            cam += input;
        }
        else if (op == 'q') {
            //cout << "consulta" << '\n';
            cout << aux[binSearch(cam) - 1] << '\n';
        }
        else if (op == 'd') {
            //cout << "delete" << '\n';
            //n--;
            add(binSearch(cam), -1);
        }
    }
}