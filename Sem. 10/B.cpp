#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool checkValid(string test) {
    string aux1;
    string aux2;

    ll pos = 0;

    for (ll i = 0; i < test.length() && test[i] != '@'; i++) {
        if (i == 0){
            if (test[i] >= '0' && test[i] <= '9') {
                return false;
            }
        }
        if ((test[i] < '0' || test[i] > '9') && (test[i] < 'a' || test[i] > 'z')) {
            return false;
        }
    }

    pos = test.find("@");
    aux1 = test.substr(0, pos);
    aux2 = test.substr(pos + 1);

    // cout << aux1 << '\n';
    // cout << aux2.length() << '\n';
    // cout << aux2 << '\n';

    pos = aux2.find("ufpr.br");

    string aux3 = "ufpr.br";

    // cout << aux3.length() << '\n';
    if (pos == 0 && aux2.length() != aux3.length() || pos == -1) {
        return false;
    }
    else if (pos != 0 && pos != -1) {
        string aux4 = aux2.substr(0, pos);
        string aux5 = aux2.substr(pos, aux2.length());

        if (aux5.length() != aux3.length()) {
            return false;
        }

        // cout << "teste " << aux4[aux4.length() - 1] << '\n';
        if (aux4[aux4.length() - 1] != '.') {
            return false;
        }

        for (int i = 0; i < aux4.length() - 1; i++) {
            if (aux4[i] < 'a' || aux4[i] > 'z') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ll q;
    cin >> q;

    vector <string> input;
    string temp;
    bool valid;
    for (ll i = 0; i < q; i++) {
        valid = false;
        cin >> temp;
        // cout << temp << '\n';
        valid = checkValid(temp);

        if (valid) {
            int count = 1;
            for (int i = 0; i < input.size(); i++) {
                if (temp.compare(input[i]) == 0) {
                    count++;
                }
            }

            cout << count << '\n';

            input.push_back(temp);
        }

        // cout << valid << '\n';
    }
}