#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string input;

    vector <string> ppl;
    for (int i = 0; i < n; i++) {
        cin >> input;
        ppl.push_back(input);
    }

    for (int i = 0; i < n; i++) {
        cout << ppl[i] << ':';
        int count = 0;
        for (int j = 0; i < n; j++) {
            if (j != i) {
                if (ppl[j].length() == ppl[i].length()) {

                }
                else if (ppl[i].length() + 1 == ppl[i].length()) {
                    
                }
            }
        }
    }
}