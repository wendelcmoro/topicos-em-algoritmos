#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a;
    cin >> b;

    set <string> desc;

    string aux;
    int bol;
    for (ll i = 0; i < a*2; i++) {
        cin >> aux;
        // cout << aux << '\n';
        // cout << desc.size() << '\n';
        //if (desc.size() > 0) {
          //  desc.erase(aux);
        //}
        //else {
        bol = desc.insert(aux).second;
        if (bol == 0) {
            desc.erase(aux);
        }
        //cout << bol << '\n';
        //}
        
        if (desc.size() >= b) {
           cout << "7.18808" << '\n';
           break;
        }
    }
   
    if (desc.size() < b) {
        cout << "3.14159" << '\n';
    }
}