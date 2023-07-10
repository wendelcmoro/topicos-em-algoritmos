#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool checkInt(long double n) {
    if (n*1 == n) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ll n;
    cin >> n;
    vector <ll> seq;
    ll temp;

    for (ll i = 0; i < n; i++) {
        cin >> temp;
        seq.push_back(temp);
    }
    
    sort(seq.begin(), seq.end());


    long double diff = 0;
    long double auxDiff = 0;
    ll count = 0;
    long double foundDiff = 0;
    ll countDiff = 0;
    ll index = 0;
    for (ll i = 0; i < n - 1; i++) {
        count++;
        diff = (long double) seq[i+1]/seq[i];
        if (i > 0) {
            if (diff != auxDiff) {
                foundDiff = 1;
                countDiff++;
            }
        }
        else {
            auxDiff = diff;
        }
    }

    //cout << foundDiff << '\n';

    if (foundDiff == 0) {
        if (seq[0]/diff == 1) {
            if (find(seq.begin(), seq.end(), 1) == seq.end()) {
                cout << 1 << '\n';
            }
        }
        else {
            long double aux = seq[0]/diff;
            //cout << roundf(aux) << '\n';
            //cout << aux << '\n';
            if (seq[0] != seq[1] && floor(aux) == aux) {
                //cout << "teste" << '\n';
                cout << fixed << setprecision(0) << seq[0]/diff << '\n';
            }
        }
        cout << fixed << setprecision(0) << seq[n - 1]*diff << '\n';
    }
    else if (countDiff >= 2) {
        ll val = seq[0];
        for (ll i = 0; i < n; i++) {
            if (i > 0) {
                val = diff*val;
                if (find(seq.begin(), seq.end(), val) == seq.end()) {
                    cout << fixed << setprecision(0) << val << '\n';
                    break;
                }
            }
        }
    }
    else if (countDiff < 2) {
        ll val = seq[0];
        for (ll i = 0; i < n; i++) {
            if (i > 0) {
                val = auxDiff*val;
                if (find(seq.begin(), seq.end(), val) == seq.end()) {
                    cout << fixed << setprecision(0) << val << '\n';
                    break;
                }
            }
        }
    }
}