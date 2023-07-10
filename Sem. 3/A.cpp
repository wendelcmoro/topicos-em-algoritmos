#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct itm { 
    ll w, v;
    string s; 
};

int main() {
    ll t;
    cin >> t;

    ll P, H, F, D, C;

    ll aux = 0;
    ll aux2 = 0;
    ll sum = 0;
    
    for (ll i = 0; i < t; i++) {
        cin >> P;
        cin >> H;
        cin >> F;
        cin >> D;
        cin >> C;

        if (C > D) {
            aux = P/2;

            if (aux > 0) {
                if (F <= aux) {
                    sum += F*C;
                    aux -= F;                    
                }
                else {
                    sum += aux*C;
                    aux = 0;
                }

                //cout << aux << '\n';

                if (aux > 0) {
                    if (H > aux) {
                        sum += aux*D;
                    }
                    else {
                        sum += H*D;
                    }
                }

                cout << sum << '\n';
                sum = 0;
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            aux = P/2;

            if (aux > 0) {
                if (H <= aux) {
                    sum += H*D;
                    aux -= H;
                }
                else {
                    sum += aux*D;
                    aux = 0;
                }

                if (aux > 0) {
                    if (F > aux) {
                        sum += aux*C;
                    }
                    else {
                        sum += F*C;
                    }
                }

                cout << sum << '\n';
                sum = 0;
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
}