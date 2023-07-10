#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//vector<vector<string>> g (1e5+15);
map<pair<string,string>,ll> g;
vector<bool> visited (1e5+15);

ll explore(pair<string,string> u) {
    ll c = 0;
    queue<pair<string,string>,ll> q;
    q.push(u);
    while (!q.empty()) {
        map<pair<string,string>,ll> u = q.front();
        q.pop();
        for (ll v : g[u]) {
            if (!visited[v]) {
                c++;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return c;
}

int main() {
    ll n;
    ll m;

    cin >> n;
    cin >> m;

    string temp1;
    string temp2;

    for (ll i = 0; i < m; i++) {
        cin >> temp1;
        cin >> temp2;

        g[make_pair(temp1,temp2)] = 1;
        g[make_pair(temp2,temp1)] = 1;
        // g[temp1].push_back(temp2);
        // g[temp2].push_back(temp1);
    }
    
    map<pair<string,string>,ll>::iterator it;
    for (it = g.begin(); it != g.end(); it++) {
        fill(visited.begin(), visited.end(), false);
        cout << explore(it) << "\n";
    }
}