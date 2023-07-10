#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    char op;

    vector <char> oper;
    list <ll> itens;

    ll cam = 0;
    ll aux1;
    ll aux2;
    for (ll i = 0; i < n; i++) {
        cin >> op;
        if (op == 'i') {
            cin >> aux1;
            cin >> aux2;
            // if (itens.size() == 0) {
            //     for (ll k = 0; k < aux1; k++) {
            //         itens.push_back(aux2);
            //     }
            // }
            // else {
            auto it = itens.begin();
            advance(it, cam);
            for (ll k = 0; k < aux1; k++) {
                itens.insert(it, aux2);
            }
                
            //}      
        }

        if (op == 'q') {
            auto it = itens.begin();
            advance(it, cam);
            cout << *it << '\n';          
        }
        if (op == 'm') {
            cin >> aux1;
            cam += aux1;
        }
        if (op == 'd') {
            auto it = itens.begin();
            advance(it, cam);
            itens.erase(it);           
        }
    }
}