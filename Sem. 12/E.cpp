#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ll n;
    while (cin >> n) {
        ll h, c, l;

        cin >> h;
        cin >> c;
        cin >> l;

        double hip = sqrt(h*h + c*c);


        cout << setprecision(4) << fixed << ((l*hip)*n)/10000 << '\n';
    }

}