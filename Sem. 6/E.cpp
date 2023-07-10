#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define N 4*100001

using ll = long long;

vector <ll> seq(N);

int main() {
    ll n;
    cin >> n;

    vector <ll> val;
    ll temp;
    for (ll i = 0; i < n; i++) {
        cin >> temp;
        val.push_back(temp);
    }

    ll base = 2;
    seq[0] = 1;
    for (ll i = 1; i < N; i++) {
        seq[i] = (2*seq[i - 1]) % MOD;
    }

    ll lastIndex = 0;
    ll sum = 0;
    while (lastIndex < n) {
        for (ll i = lastIndex + 1; i < n; i++) {
            if (val[lastIndex] < val[i]) {
                sum = (sum + seq[i - lastIndex - 1]) % MOD;
            }
        }
        lastIndex++;
    }
 
    cout << sum << '\n';
}