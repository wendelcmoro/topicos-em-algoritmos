#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
ll modInverse(ll b, ll m) {
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
 
    if (g != 1) {
        return -1;
    }

    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
ll modDivide(ll a, ll b, ll m) {
    a = a % m;
    int inv = modInverse(b, m);
    // if (inv == -1)
    //    cout << "Division not defined";
    // else
    //    cout << "Result of division is " << (inv * a) % m;
    
    return (inv * a) % m;
}

// ll factorial(ll n, ll p) {
//     ll ans = 1;

//     for(int i = 2;i <= n; i++) {
//         ans = (ans*i) % p;
//     }
    
//     return ans;
// }

int main() {
    ll d;
    ll c;

    cin >> d;
    cin >> c;

    ll temp;
    ll temp2;

    vector <ll> balls;
    ll wildcards[d+1] = {0};

    ll countWildcards = 0;

    for (ll i = 0; i < d; i++) {
        cin >> temp;
        balls.push_back(temp);
    }

    for (ll i = 0; i < c; i++) {
        cin >> temp;
        cin >> temp2;

        wildcards[temp2 - 1]++;
        // auto it = find_if(begin(wildcards), end(wildcards),
        //     [ = ]( auto item ) {
        //             return (get<0>(item) == temp2);
        //         }
        // );

        // if (it == wildcards.end()) {        
        //     wildcards.push_back(make_tuple(temp2, 1));
        // }
        // else {
        //     get<1>(*it)++;
        // }
    }

    ll aux = 1;
    ll aux2 = 1;
    ll div = 1;

    ll result = 1;

    ll fat[10000+1];
    fat[0] = 1;

    for (ll i = 1; i <= 10000; i++) {
        fat[i] = (i*fat[i-1]) % 1000000007;
    }

    // for (ll i = 1; i <= 10; i++) {
    //     cout << fat[i] << '\n';
    // }

    for (ll i = 0; i < d; i++) {
        // auto it = find_if(begin(wildcards), end(wildcards),
        //     [ = ]( auto item ) {
        //             return (get<0>(item) == i + 1);
        //         }
        // );

        // if (it == 0) {
        //     aux = factorial(balls[i], 1000000007);
        //     aux2 = factorial(balls[i] - d, 1000000007);
        //     div = modDivide(aux, aux2, 1000000007);

        //     result = (result*div) % 1000000007;
        // }
        //else {
            // aux = factorial(balls[i], 1000000007);
            // aux2 = factorial(balls[i] - (d - wildcards[i]), 1000000007);
            // cout << balls[i] << '\n';
            // cout << balls[i] - (d - wildcards[i]) << '\n';
            div = modDivide(fat[balls[i]], fat[balls[i] - (d - wildcards[i])], 1000000007);

            result = (result*div) % 1000000007;
        //}
    }

    cout << result << '\n';
}