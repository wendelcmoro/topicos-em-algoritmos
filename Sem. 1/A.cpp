#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ll n;
    ll diff = 0;
    ll auxDiff = 0;

   while (cin >> n) {
        diff = 0;
        vector<ll> f;
        
        f.resize(n);

        vector<ll> s;
        s.resize(n/2);

        for (auto it = f.begin(); it != f.end(); it++) {
            cin >> *it;
        }

        for (auto it = s.begin(); it != s.end(); it++) {
            cin >> *it;
        }

        for (auto it = s.begin(); it != s.end(); it++) {
            if (f.front() + f.back() != *it) {
                auxDiff = f.front() + f.back() - *it;

                if (auxDiff < 0) {
                    diff += auxDiff*(-1);
                }
                else {
                    diff += auxDiff;
                }
            }
            f.pop_back();
            f.erase(f.begin());
        }

        cout << diff << '\n';
    }

}