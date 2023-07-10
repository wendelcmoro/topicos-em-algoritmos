#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    string x,y;

    ll xA, xB;
    while (t > 0) {
        cin >> x;
        cin >> y;

        xA = x.back() - 48;
        xB = y.back() - 48;

        if ((xA + xB) % 2 == 1) {
            cout << "NAO PARCEIROS\n";
        }
        else {
            cout << "PARCEIROS\n";
        }
        t--;
    }
}