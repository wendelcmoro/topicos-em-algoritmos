#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
    ll h;
    ll n;
    ll v;

    cin >> h;
    cin >> n;
    cin >> v;
    
    ll mod = v % n;
    ll resul;
    resul = v/h;

    resul = resul/n + bool(resul % n);
    cout << fixed;
    cout << setprecision(0);
    cout << resul << '\n';
}