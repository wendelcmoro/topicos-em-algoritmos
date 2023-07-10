#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> nxt;

ll z, i, m, l;

ll succ(ll x) { 
    return (z * x + i) % m;
}

struct cyc {
    ll prev, first, len;
};

cyc find_cycle(ll start) {
    ll a = start, b = start;

    do {
        a = succ(a);
        b = succ(succ(b));
    } while (a != b);

    a = start;
    ll prev = -1;

    while (a != b) {
        prev = a;
        a = succ(a);
        b = succ(b);
    }

    ll len = 0;
    do {
        b = succ(b);
        len++;
    } while (a != b);

    return {.prev = prev, .first = a, .len = len};
}

int main() {
    ll n = 1;

    cin >> z;
    cin >> i;
    cin >> m;
    cin >> l;

    while (z != 0 || i != 0 || m !=0 || l != 0) {

        cyc res = find_cycle(l);
        
        cout << "Case " << n << ": " << res.len << '\n';
        
        n++;

        cin >> z;
        cin >> i;
        cin >> m;
        cin >> l;
    }
}