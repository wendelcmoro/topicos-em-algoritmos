#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPerfectSquare(ll x) {
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

int main() {
    ll n;
    cin >> n;

    

    ll sol = 0;
    //ll nPow = pow(n, 2);
    
    // vector<ll> sQs;

    // for (ll i = 1; i <= nPow; i++) {
    //     if (isPerfectSquare(i)) {
    //         sQs.push_back(i);
    //     }
    // }

    // ll size = sQs.size();
    // for (ll i = 0; i < size; i++) {
    //     cout << sQs[i] << ' ';
    // }
    // cout << '\n';
    // for (ll i = 0; i < size; i++) {
    //     long double sqI = sqrt(sQs[i]);
        
    //     if (sqI < n) {
    //         for (ll j = i; j < size; j++) {
    //             long double sqJ = sqrt(sQs[j]);
                
    //             if (sqJ + sqI < n) {
    //                 for (ll k = j; k < size; k++) {
    //                     long double sqK = sqrt(sQs[k]);

    //                     if (sqI + sqJ + sqK <= n) {
    //                         if (sQs[i] >= 1 && sQs[i] <= sQs[j] && sQs[i] <= sQs[k] && sQs[j] <= sQs[k]) {
    //                             if ((sqI + sqJ + sqK) == n) {
    //                                 sol++;
    //                             }
    //                         }
    //                     }
    //                     else {
    //                         break;
    //                     }
    //                 }
    //             }
    //             else {
    //                 break;
    //             }
    //         }
    //     }
    //     else {
    //         break;
    //     }
    // }

    for (ll i = 1; i < n; i++) {
        for (ll j = i; j < n; j++) {
            if (n - (j + i) >= j) {
                //cout << i << ' ' << j << ' ' << n - (j + i) << '\n';
                sol++;
            }
        }
    }

    cout << sol << '\n';
}