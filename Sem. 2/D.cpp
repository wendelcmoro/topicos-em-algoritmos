#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll calc(ll n, ll pow, ll mod) {
    if(n == 0 || n == 1)  {
          return n % mod;
      }

    if (pow == 0) {
        return 1;
    }

    if(mod == 1) {
        return 0;
    }

    ll ans = 1;

    while(pow) {
        if(pow % 2) {
            ans = (ans*n) % mod;
        }

        n = (n*n) % mod;

        pow /= 2;
    }

    return ans;
}

int main() {
    ll n;
    ll input;
    cin >> n;
    ll auxS = 0;
    ll aux;

    for (ll i = 0; i < n; i++) {
        cin >> input;

        ll nines = input/9;

        ll pot = calc(10, nines, 1000000007);
        //cout << pot << '\n';
        pot = pot - 1;
        
        ll rest = input % 9;
        ll potAux = calc(10, nines, 1000000007);
        rest = (rest*potAux) % 1000000007;

        pot = pot;

        ll res = rest + pot;
        cout << res % 1000000007 << '\n';
    }
}