#include <bits/stdc++.h>
using namespace std;
using ll = int;

#define mset(x, y) memset(&x, (y), sizeof(x))

ll dp[10001*5002];
ll pencils = 0;
ll length = 0;

ll index(ll i, ll j) {
    ll calc1 = i*10001 + j;
    ll calc2 = ((0 + length*j)*(j + 1))/2;
    
    return calc1 - calc2;
}
void calc(vector <ll> &numbers) {

    for (ll i = 0; i < numbers.size(); i++) {
        if (i == 0) {
            dp[index(0, i)] = numbers[0];
        }
        else {
            dp[index(0, i)] = numbers[i] + dp[index(0, i - 1)];
        }
    }
     
    for (ll j = 1; j <= pencils; j++) {
        for (ll i = length*j; i < numbers.size(); i++) {
            dp[index(j, i)] = max(dp[index(j, i - 1)] + numbers[i], dp[index(j - 1, i - length)]);
        }
    }
    cout << dp[index(pencils, numbers.size() - 1)] << endl;

}
    

int main() {
    ll squares;
    
    vector <ll> numbers;

    cin >> squares;
    cin >> pencils;
    cin >> length;   

    ll temp;
    for (ll i = 0; i < squares; i++) {
        cin >> temp;
        numbers.push_back(temp);
    }

    mset(dp, 0);
    
    calc(numbers);
}