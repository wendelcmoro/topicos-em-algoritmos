#include <bits/stdc++.h>
using namespace std;

vector<int> borders(string ne) {
    int n = ne.size();
    vector<int> pi(n, 0);

    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && ne[i] != ne[j]) {
            j = pi[j - 1];
        }

        if (ne[i] == ne[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}


int main() {
    string input;

    cin >> input;

    vector <int> pi = borders(input);

    vector <int> res;

    int border;
    for (int  i = pi.size() - 1; i >= 0; i = border - 1) {
        border = pi[i];

        if (border != 0) {
           res.push_back(border);
        }

        if (border == 0) {
            break;
        }
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }

    cout << '\n';
}