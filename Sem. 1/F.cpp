#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector <ll> fifo;
    vector <ll> lifo;
    vector <ll> pri;

    ll p, age;

    int priority = 1;
    int lastOp = 0;
    for (ll i = 0; i < n; i++) {
        cin >> p;
        cin >> age;
        if (p == 0) {
            fifo.push_back(age);
            lifo.push_back(age);

            if (lastOp == 1 && priority == 1) {
                for (ll i = 0; i < pri.size() - 1; i++) {
                    if (pri[i] < pri[i+1]) {
                        priority = 0;
                        break;
                    }
                }
                pri.clear();
            }

            lastOp = 0;
            
        }
        else if (p == 1) {
            pri.push_back(age);

            lastOp = 1;
            if (fifo.front() == age) {
                fifo.erase(fifo.begin());
            }
            if (lifo.back() == age) {
                lifo.pop_back();
            }
        }
    };

    if (priority == 1) {
        for (ll i = 0; i < pri.size() - 1; i++) {
            if (pri[i] < pri[i+1]) {
                priority = 0;
                break;
            }        
        }
    }

    ll fifoSize = fifo.size();
    ll lifoSize = lifo.size();
 
    if (fifoSize == 0 && lifoSize > 0 && priority == 0) {
        cout << "fifo\n";
    }
    else if (lifoSize == 0 && fifoSize > 0 && priority == 0) {
        cout << "lifo\n";
    }
    else if (priority == 1 && fifoSize > 0 && lifoSize > 0) {
        cout << "priority\n";
    }
    else if (fifoSize == 0 || lifoSize == 0 || priority == 1) {
        cout << "ambiguous\n";
    }
    else {
        cout << "unknown\n";
    }
}