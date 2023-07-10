#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string code;
    ll h;
    ll m;

    vector <tuple<string, ll, ll>>subject;

    while (cin >> code) {
        cin >> h;
        cin >> m;
        subject.push_back(make_tuple(code, h, m));
    }

    double auxH;
    for (auto i : subject) {
        auxH = get<1>(i);
        auxH += get<2>(i)/60.0;
        //cout << get<2>(i)/60.0 << '\n';
        if (auxH > 10) {
            cout << "Abel deve cancelar " << get<0>(i) << '\n';
        }
        else {
            cout << "Abel deve cursar " << get<0>(i) << '\n';
        }
        // cout << auxH << '\n';
        // cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << '\n';
    }

}