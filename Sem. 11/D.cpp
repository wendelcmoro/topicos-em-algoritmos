#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ll n;
    ll k;

    cin >> n;
    cin >> k;

    ll input;

    vector <ll> seq;
    for (ll i = 0; i < n; i++) {
        cin >> input;
        seq.push_back(input);
    }

    if (n == 2 && seq[0] == seq[1]) {
        cout << "Dila\n";
        return 0;
    }
    else {
        if (n % 2 != 0) {
            n++;
            seq.insert(seq.begin(), 0);
        }

        int g = 0;

        for (int i = 0; i < (n / 2); i++) {
            g ^= ((seq[2 * i + 1] - seq[2 * i]) % (k + 1));
        }

        if (g == 0) {
            cout << "Dila\n";
        }
        else {
            cout << "Dali\n";
        }
    }
}