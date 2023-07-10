#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main() {
    ll n;
    cin >> n;

    ll a, b;

    ll tam = 300000;
    vector<bool> sieve (tam + 1, true);
    vector<ll> seq;
    for (ll i = 2; i * i <= tam; i++) {
        if (sieve[i]) {
            for (ll j = i * i; j <= tam; j += i) {
                sieve[j] = false;
            }
        }     
    }

    for (ll i = 0; i < n; i++) {
        cin >> a;
        cin >> b;        

        // for (ll i = 2; i <= a; i++) {
        //     if (sieve[i]) { 
        //         cout << i << " "; 
        //     }
        // }
        // cout << '\n';
        
        ll count = 0;
        ll prod = 0;
        ll auxProd = 0;
        for (ll j = 2;  j <= a; j++) {
            if (sieve[j]) {
                seq.push_back(j);
                count++;
                if (count == b) {
                    for (ll k = 0; k < seq.size(); k++) {
                        //cout << seq[k] << ' ';
                        if (k > 0) {
                            auxProd = auxProd*seq[k];
                        }
                        else {
                            auxProd = seq[k]*seq[k+1];
                            k++;
                        }
                        if (auxProd > a) {
                            break;
                        }
                        //cout << prod << '\n';                        
                    }
                    //cout << prod << '\n'; 
                    if (auxProd > a) {
                        cout << prod << '\n';
                        break;
                    }
                    else if (auxProd <= a) {
                        prod = auxProd;
                        count--;
                        seq.erase(seq.begin());
                    }
                }
                //cout << '\n';
            }
        }

        seq.clear();
    }
}