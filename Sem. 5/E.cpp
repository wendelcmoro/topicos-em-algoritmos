#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Max number of nodes given
const ll N = 3200;
 
// arr is the parent array
// sz is the size of the
// subtree in DSU
ll arr[N], sz[N];
 
// Function to initialize the parent
// and size array for DSU
void initialize()
{
    for (ll i = 1; i < N; ++i) {
        arr[i] = i;
        sz[i] = 1;
    }
}
 
// Function to return the
// parent of the node
ll root(ll i)
{
    while (arr[i] != i)
        i = arr[i];
    return i;
}
 
// Function to perform the
// merge operation
void un(ll a, ll b)
{
    a = root(a);
    b = root(b);
 
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
 
        sz[a] += sz[b];
        arr[b] = a;
    }
}
 
// Function to return the minimum cost required
double minCost(vector<pair<ll, ll> >& p)
{
 
    // Number of polls
    ll n = (ll)p.size();
 
    // To store the cost of every possible pair
    // as { cost, {to, from}}.
    vector<pair<double, pair<ll, ll> > > cost;
 
    // Calculating the cost of every possible pair
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i != j) {
 
                // Getting Manhattan distance
                ll x = abs(p[i].first - p[j].first)
                        + abs(p[i].second - p[j].second);
 
                // If the distance is 1 the cost is 0
                // or already connected
                if (x == 1) {
                    cost.push_back({ 0, { i + 1, j + 1 } });
                    cost.push_back({ 0, { j + 1, i + 1 } });
                }
                else {
 
                    // Calculating the euclidean distance
                    ll a = p[i].first - p[j].first;
                    ll b = p[i].second - p[j].second;
                    a *= a;
                    b *= b;
                    double d = sqrt(a + b);
                    cost.push_back({ d, { i + 1, j + 1 } });
                    cost.push_back({ d, { j + 1, i + 1 } });
                }
            }
        }
    }
 
    // Krushkal Algorithm for Minimum
    // spanning tree
    sort(cost.begin(), cost.end());
 
    // To initialize the size and
    // parent array
    initialize();
 
    double ans = 0.00;
    for (auto i : cost) {
        double c = i.first;
        ll a = i.second.first;
        ll b = i.second.second;
 
        // If the parents are different
        if (root(a) != root(b)) {
            un(a, b);
            ans += c;
        }
    }
 
    return ans;
}

int main() {
    ll n;
    ll A;
    ll C;

    vector<pair<ll, ll> > points;

    cin >> n;
    cin >> A;
    cin >> C;

    ll a;
    ll b;
    ll temp;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        points.push_back(make_pair(a, b));
    }

    ll m;
    char c;
    for (ll i = 0; i < m; i++) {
        cin >> a;
        cin >> b;
        cin >> c;

        if (c == 't') {
            temp = A;
        }
        else {
            temp = C;
        }
        
    }

    cout << setprecision(16);
    cout << minCost(points) << '\n';
}