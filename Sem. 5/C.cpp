#include <bits/stdc++.h>
using namespace std;
using ll  = long long;

ll N = 120000;
const ll L = log2(N);

vector<ll> depth (N, 0);
vector<vector<ll>> weiop (N, vector<ll>(L+1));
vector<vector<ll>> up (N, vector<ll>(L+1));

typedef pair<ll, ll> edge;

vector<vector<edge>> g(N);


ll bl_op(ll a, ll b) {

    // cout << "gerando saida para " << a << " e " << b << '\n';

    if (depth[b] > depth[a]) {
        swap(a, b);
    }
    ll res = 0;
    ll diff = depth[a] - depth[b];
    for (ll l = L; l >= 0; l--) {
        if (diff & (1 << l)) {
            res += weiop[a][l];
            // cout << "res parcial" << a << '\n';
            a = up[a][l];
        }
    }

    if (a == b) {
        // cout << "aa\n";
        return res;
    }

    for (ll l = L; l >= 0; l--) {
        if (up[a][l] != up[b][l]) {
            //res = (res + weiop[a][l]) + weiop[b][l];
            res += weiop[a][l] + weiop[b][l];
            // cout << "res parcial " << a << ' ' << b << ' ' << l << '\n';
            a = up[a][l];
            b = up[b][l];
        }
    }

    return  res + weiop[a][0] + weiop[b][0];
}

void bl_euler_tour(ll u, ll p, ll w) {
    up[u][0] = p;
    weiop[u][0] = w;
    depth[u] = depth[p] + 1;
    for (auto [v, w] : g[u]) {
        if (v != p) {
            bl_euler_tour(v, u, w);
        }
    }
}

void bl_init(ll u, ll n) {
    depth[u] = 0;
    bl_euler_tour(u, u, 0);
    for (ll l = 0; l < L; l++) {
        for (ll u = 0; u < n; u++) {
            ll a = up[u][l];
            up[u][l + 1] = up[a][l];
            weiop[u][l + 1] = weiop[u][l] + weiop[a][l];
        }
    }
}

int main() {
    ll n;

    cin >> n;

    ll A, B;
    ll temp;
    for (ll i = 1; i < n; i++) {
        cin >> A;
        cin >> B;
        // cout << "indice i:" << i << '\n';
        
        g[A].push_back(make_pair(i, B));
        g[i].push_back(make_pair(A, B));
        // up[i][A] = i;
        // up[A][i] = A;
        
        // weiop[i][A] = B;
        // weiop[A][i] = B;
    }
    bl_init(0, n);

    // for (ll   i = 0; i < n; i++) {
    //     for (ll j = 0; j < n; j++) {
    //         cout << up[i][j] << ' ';
    //     }

    //     cout << '\n';
    // }

    // cout << '\n';
    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < n; j++) {
    //         cout << weiop[i][j] << ' ';
    //     }

    //     cout << '\n';
    // }

    ll q;
    cin >> q;

    for (ll i = 0; i < q; i++) {
        cin >> A;
        cin >> B;

        // cout << "computando resposta para: " << A << ' ' << B << '\n';
        cout << bl_op(A, B) << '\n';
    }
}