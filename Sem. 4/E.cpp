#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll A;
    ll B;
    ll C;

    cin >> A;
    cin >> B;
    cin >> C;

    ll delta = (B*B) - 4 * A * C;
    double sqrtDelta = sqrt(delta);
    
    if (delta == ((ll)sqrtDelta)*((ll)sqrtDelta)) {
        cout << 'Y' << '\n';
    }
    else {
        cout << 'N' << '\n';
    }
}