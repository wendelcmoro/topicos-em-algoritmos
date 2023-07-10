#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N = 10000001;
vector <ll> digits(N);
vector <ll> fact(N);
vector <ll> fDigit(N);

void count_digits() {
    digits[1] = 1;

    double d = 0;
    ll aux = 1;
    fDigit[1] = 1;
    for (ll i = 2; i < N; i++) {
        d += log10(i);
        digits[i] = floor(d) + 1;
        fDigit[i] = pow(10, d - floor(d));
    }
}

int main() {
    count_digits();

    ll t;
    cin >> t;

    ll num;
    for (ll i = 0 ; i < t; i++) {
        cin >> num;
        cout << fDigit[num] << ' ';
        cout << digits[num] << '\n';
    }
}