#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15;
int cts = 1;
vector<int> vis(N);
vector<vector<int>> g (N);
vector<int> rep (N);

void mark_component(int u, int r) {
    if (vis[u] == cts) {
        return;
    }
    vis[u] = cts;
    rep[u] = r;
    for (int v : g[u]) {
        mark_component(v, r);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int u = 0; u < n; u++) {
        mark_component(u, u);
    }
    for (int u = 0; u < n; u++) {
        cout << rep[u] + 1 << " ";
    }
}