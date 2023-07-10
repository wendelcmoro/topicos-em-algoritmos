#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll oo = 987654321;
const ll N = 1e4 + 15;
#define pb push_back

vector<vector<ll>> res(N);
struct edge {
    ll u, v, cap;
};

vector<edge> edges;
vector<ll> ix(N), dist(N), par(N);

bool minimum_path(ll s, ll t) {
    fill(dist.begin(), dist.end(), oo);
    dist[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        if (u == t) {
            break;
        }
        for (ll i : res[u]) {
            edge e = edges[i];
            ll v = e.v;
            if (e.cap && dist[v] == oo) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                ix[v] = i;
                q.push(v);
            }
        }
    }
    return dist[t] < oo;
}

pair<ll, ll> ffek(ll s, ll t) {
    ll min_cost = 0, max_flow = 0;
    while (minimum_path(s, t)) {
        ll flow = oo;
        for (ll u = t; u != s; u = par[u]) {
            flow = min(flow, edges[ix[u]].cap);
        }
        for (ll u = t; u != s; u = par[u]) {
            edges[ix[u]].cap -= flow;
            edges[ix[u] ^ 1].cap += flow;
        }
        min_cost += flow * dist[t];
        max_flow += flow;
    }
    return {min_cost, max_flow};
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;

        res[u].pb(edges.size());
        edges.pb({u, v, c});
        res[v].pb(edges.size());
        edges.pb({v, u, 0});
    }

    auto [min_cost, max_flow] = ffek(0, n - 1);

    cout << max_flow << "\n";

    // for (ll i = 0; i < 2 * m; i++) {
    //     ll max = 0;
    //     if (i % 2 && edges[i].cap) {
    //         edge e = edges[i];
    //         cout << e.v + 1 << " -> " << e.u + 1;
    //         cout << " used=" << e.cap << "\n";

    //         if (e.cap > max) {
    //             max = e.cap;
    //         }
    //     }
    // }
}