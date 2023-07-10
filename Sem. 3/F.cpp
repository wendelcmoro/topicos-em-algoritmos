#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 40000
string res = "";

ll n;
ll m;

void lcs(string X, string Y) {
    ll L[m+1][n+1];
  
    for (ll i = 0; i <= m; i++) {
        for (ll j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            }
            else if (X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            }
            else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    
    ll index = L[m][n];
    
    if (index > 0) {
        char lcs[index+1];
        lcs[index] = '\0';

        ll i = m;
        ll j = n;
        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                lcs[index - 1] = X[i - 1];
                i--;
                j--;
                index--;
            }
        
            else if (L[i - 1][j] > L[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }

        cout << lcs << '\n';
    }
    else {
        cout << '\n';
    }
}

int main() {
    string Y;
    string X;

    cin >> Y;
    cin >> X;

    n = Y.size();
    m = X.size();
    
    //cout << lcs(X, Y) << '\n';
    lcs(X, Y);
}