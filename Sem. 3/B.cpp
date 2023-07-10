#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll coins[] = {1 , 5, 10, 25, 50};
ll lastAmmount = 1;
// ll table[40000];
ll dp[5][40000];

ll comb(ll n, ll amount) {
    // memset(table, 0, sizeof(table)); 
    // table[0] = 1;
    // ll aux = 1;
    // for(ll i = 0; i < n; i++) {
    //     for(ll j = lastAmmount; j <= amount; j++) {
    //         if (j - coins[i] >= 0) {
    //             //if (table[j - coins[i]] == 0)                    
    //                 table[j] += table[j - coins[i]];
    //                 aux = j;
    //                 cout << "debug " << amount << ' ' << i << ' ' << j << ' ' << table[j] << '\n';
    //             //}
    //         }
    //     }
    // }

    // lastAmmount = aux;

    // return table[amount];  

    // for (ll i = 1; i < n; i++) {
    //     for (ll j = 1; j <= amount; j++) {
    //         if (j == 0) {
    //             dp[i][j] = 1;
    //             continue;
    //         }
    //         if (i == 0) {
    //             dp[i][j] = (j % coins[i] == 0) ? 1 : 0;
    //             continue;
    //         }
    //         if (j >= coins[i]) {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
    //         }
    //         else {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }
    ll aux = 1;
    for (ll i = 1; i < n; i++) {
        for (ll j = lastAmmount; j <= amount; j++){
            if (j >= coins[i]) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }

            aux = j;
        }
    }

    lastAmmount = aux;
    return dp[n - 1][amount];
}

int main() {   
    ll val;
    for (ll i = 0; i < 5; i++) {
        dp[i][0] = 1;
    }

    for (ll j = 1; j <= 40000; j++) {
        dp[0][j] = 1;
    }
    
    while (cin >> val) {
        cout << comb(5, val) << '\n';
        // lastAmmount = val;
    }

}