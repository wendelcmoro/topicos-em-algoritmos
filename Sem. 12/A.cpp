#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPerfectSquare(double n){
    double t = sqrt(n);
    
    // cout << t << '\n';
    ll r = floor(t);

    // cout << r*r << '\n';

    if(r*r == n) {
        return true;
    }

    return false;
}

int main() {
    ll n;
    cin >> n;

    ll input;
    for (ll i = 0; i < n; i++) {
        cin >> input;
        
        if (isPerfectSquare((double) input/4) || isPerfectSquare((double) input/2)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

}