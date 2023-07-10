#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) { 
        return a;
    }
    return gcd(b, a%b);
}

ll lcm (ll a, ll b) {
  return a*(b/gcd(a, b));
}

ll count(vector<ll> &primes, ll a, ll b) {
    ll sum = 0;
    
    for (ll msk = 1; msk < (1 << primes.size()); ++msk) {
        ll mult = 1,
        bits = 0;
        bool overflow = false;

        for (ll i = 0; i < primes.size(); ++i) {
            
            if (msk & (1 << i)) {
                ++bits;
                ll temp = lcm(mult, primes[i]);

                if (temp % primes[i] == 0 && temp % mult == 0) {
                    mult = temp;
                }
                else {
                    overflow = true;
                }
            }
        }

        if (mult > b || overflow) {
            continue;
        }
        ll aux = (b/mult)*mult;
        ll aux2 = (a/mult)*mult;

        if (a % mult != 0) {
            aux2 += mult;
        }

        ll cur = (aux/mult - aux2/mult) + 1;

        if (bits % 2 == 1) {
            sum += cur;
        }
        else {
            sum -= cur;
        }
    }

    return sum;
}

int main() {
    ll a, b, n;

    cin >> a;
    cin >> b;
    cin >> n;

    vector<ll> primes;

    ll temp;
    for (ll i = 0; i < n; i++) {
        cin >> temp;
        primes.push_back(temp);        
    }
    
    //ll m = sizeof(primes)/ sizeof(primes[0]);
    ll size = count(primes, a, b);
    

    cout << (b - a + 1) - size << '\n';
}