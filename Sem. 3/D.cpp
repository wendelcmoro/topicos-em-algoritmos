#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    string test;
    ll open;

    for (ll i = 0; i < n; i++) {
        cin >> test;
        open = 0;

        for (ll j = 0; j < test.size(); j++) {
            // count++;
            //else {
            if (test[j] == '_') {
                open++;
                //cout << open << '\n';
                j += 2;
            }
            //}
        }

        cout << "Caso " << i + 1 << ": " << open << '\n';
    }

}