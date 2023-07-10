#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 210000;

#define OP(X, Y) (X * Y)
#define NEUTRAL 1

ll op_inclusive(ll l, ll r, vector<ll> &num) {
    r++;

    ll left = NEUTRAL, right = NEUTRAL;

    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            left = OP(left, num[l++]);
        }
        if (r & 1) {
            right = OP(right, num[--r]);
        }
    }

    return OP(left, right);
}

void set_value(ll i, ll v, vector<ll> &num) {
    num[i += N] = v;
    for (i /= 2; i > 0; i /= 2) {
        num[i] = OP(num[i*2], num[i*2+1]);
    }
}

int main() {
    ll n;
    ll k;

    cin >> n;
    cin >> k;
    
    vector <ll> num(10000000);

    ll temp;
    for (ll i = 1; i <= n; i++) {
        cin >> temp;
        if (temp > 0) {
            temp = 1;
        }
        else if (temp < 0) {
            temp = -1;
        }
        else {
            temp = 0;
        }
        set_value(i, temp, num);
    }

    char car;
    ll temp2;
    ll resul;
    for (ll i = 0; i < k; i++) {
        cin >> car;
        cin >> temp;
        cin >> temp2;
        
        if (car == 'A') {
            //cout << temp << ' ' << temp2 << '\n';
            if (temp2 > 0) {
                temp2 = 1;
            }
            else if (temp2 < 0) {
                temp2 = -1;
            }
            else {
                temp2 = 0;
            }

            set_value(temp, temp2, num);
        }
        else {
            resul = op_inclusive(temp, temp2, num);

            //cout << resul << '\n';
            if (resul == 0) {
                cout << '0';
            }
            else if (resul < 0) {
                cout << '-';
            }
            else {
                cout << '+';
            }
            //cout << '\n';
        }
    }
    cout << '\n';
}