#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define llinf 0x3f3f3f3f3f3f3f3f

ll N = 14000;

struct edge { 
    ll u, v, w;
};

vector<edge> edges;
vector <ll> d(N, llinf);

ll bellman_ford(ll src, ll dest, ll n) {
    d[src] = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (auto e : edges) {
            if (d[e.u] != llinf && d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
            }
        }
    }

    for (auto e : edges) {
        if (d[e.u] != llinf && d[e.v] > d[e.u] + e.w) {
            return -llinf;
        }
    }
    return d[dest];
}

int main() {
    //cout << llinf << '\n';
    ll n;

    cin >> n;
    vector <ll> lot(N);

    ll temp;
    for (ll i = 1; i <= n; i++) {
        cin >> temp;
        lot[i] = temp;
    }

    ll m;
    cin >> m;

    ll A, B;
    edge tE;
    for (ll i = 1; i <= m; i++) {
        cin >> A;
        cin >> B;

        temp = lot[B]- lot[A];
        
        tE.u = A;
        tE.v = B;
        tE.w = temp;
        edges.push_back(tE);
    }

    ll q;
    cin >> q;

    ll res = 0;

    bellman_ford(1, n, n) << '\n';

    // for (ll i = 1; i <= n; i++) {
    //     cout << d[i] << '\n';
    // }
    
    for (ll i = 0; i < q; i++) {
        cin >> temp;
        if (d[temp] < 3 || d[temp] == llinf) {
            cout << "Não, Edsger...\n";
        }
        else {
            cout << d[temp] << '\n';
        }
    }
}