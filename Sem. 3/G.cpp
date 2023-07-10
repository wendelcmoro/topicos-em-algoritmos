#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    ll q;

    cin >> n;
    cin >> q;

    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    bitset<100001> valor (s);
    
    ll ones = valor.count();

    char opA;
    ll opB;

    for (ll i = 0; i < q; i++) {
        cin >> opA;
        cin >> opB;

        if (opA == 't') {
            if (s[opB - 1] == '1') {
                s[opB - 1] = '0';
                ones--;
            }
            else {
                s[opB - 1] = '1';
                ones++;
            }
        }
        else if (opA == 'k') {
            if (opB > ones) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
    }

}