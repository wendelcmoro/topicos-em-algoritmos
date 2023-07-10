#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll books;
ll countRest;
vector<ll> s (100000);
vector<bool> chosen (100001);

void gen(ll b, vector<tuple<ll, ll>> &rest, vector<ll> &booksOrder) {
    
    if (b == books) {
        for (ll i = 0; i < books; i++) {
            booksOrder[i] = s[i];
            //cout << s[i] << ' ';
        }

        int valid = 0;
        ll rule1;
        ll rule2;
        ll ind1 = -1;
        ll ind2 = -1;
        for (auto j : rest) {
            ind1 = -1;
            ind2 = -1;
            rule1 = get<0>(j);
            rule2 = get<1>(j);

            for (ll i = 0; i < books; i++) {
                if (booksOrder[i] == rule1) {
                    ind1 = i;
                } 
                else if (booksOrder[i] == rule2) {
                    ind2 = i;
                }

                if (ind1 != -1  && ind2 != -1) {
                    break;
                }
            }

            if (ind1 > ind2) {
                valid = 1;
                return;
            }            
        }
        
        if (valid == 0) {
            for (ll i = 0; i < books; i++) {
                cout << booksOrder[i] << ' ';
            }
            cout << '\n';
        }         

        
        return;
    }
    for (ll i = 1; i <= books; i++) {
        if (!chosen[i]) {
            int valid = 0;

            ll rule1;
            ll rule2;
            ll ind1;
            ll ind2;
            for (auto l : rest) {
                ind1 = -1;
                ind2 = -1;
                rule1 = get<0>(l);
                rule2 = get<1>(l);

                for (ll k = 0; k < b; k++) {
                    if (s[k] == rule1) {
                        ind1 = k;
                    }
                    else if (s[k] == rule2) {
                        ind2 = k;
                    }

                    if (ind2 != -1 && ind1 == -1) {
                        return;
                    }

                    if (ind1 != -1  && ind2 != -1) {
                        break;
                    }
                }

                if (ind1 != -1 && ind2 != -1 && ind1 > ind2) {
                    valid = 1;
                    return;
                }
            }
            
            if (valid == 0) {
                chosen[i] = 1;
                s[b] = i;
                gen(b + 1, rest, booksOrder);
                chosen[i] = 0;
            }
            else {
                return;
            }
        }
    }
}

int main() {
    ll a, b;

    cin >> books;
    cin >> countRest;

    vector<tuple<ll, ll>> rest;

    vector<ll> booksOrder(books);

    for (ll i = 0; i < countRest; i++) {
        cin >> a;
        cin >> b;
        rest.push_back(make_tuple(a, b));
    }

    gen(0, rest, booksOrder);
    // cout << '\n';
}