#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ii = pair<ll, ll>;

void dfs(ll u, ll p, set<ll> &arti, vector<ii> &brid, vector<vector<ll>> &g, ll tk, vector <ll> &tin, vector <ll> &low) {
    tin[u] = low[u] = tk++;
    ll ch = 0;
    for (auto v : g[u]) {
        if (v == p) {
            continue;
        }
        else if (tin[v] == -1) {
            dfs(v, u, arti, brid, g, tk, tin, low);
            ch++;
            if ((low[v] >= tin[u] && p != u) || (ch >= 2 && p == u)) {
                arti.insert(u);
            }
            if (low[v] > tin[u]) {
                brid.push_back(ii(u, v));
            }
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

int main() {
    ll t;

    cin >> t;

    ll n;
    ll m;
    for (ll i = 0; i < t; i++) {
        cin >> n;
        cin >> m;

        vector<vector<ll>> g(n);

        for (ll j = 0; j < m; j++) {
            ll x;
            ll y;
            cin >> x;
            cin >> y;
            
            x--;
            y--;
            
            g[x].push_back(y);
            g[y].push_back(x);
        }
        

        vector<ii> brid;
        set<ll> arti;
        ll tk = 0;
        vector<ll> tin (n, -1), low (n);

        for (ll j = 0; j < n; j++) { 
            dfs(j, j, arti, brid, g, tk, tin, low);
        }

        ll count = 0;
        for (auto [u, v] : brid) {
            count += 1;
            //cout << u+1 << " " << v+1 << "\n";
        }

        cout << count << '\n';
    }
}