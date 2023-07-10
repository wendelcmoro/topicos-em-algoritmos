#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool sortbyth(const tuple<ll, int, ll>& a, const tuple<ll, int, ll>& b) {
    if (get<0>(a) < get<0>(b)){
        return 1;
    }
    else if (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b)) {
        return 1;
    }
    else if (get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) > get<2>(b)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    ll files;
    ll del;

    cin >> files;
    cin >> del;

    vector <tuple<ll, int, ll>>fileList;

    string extAux;
    ll descAux;
    ll sizeAux;

    for (ll i = 0; i < files; i++) {
        cin >> descAux;
        cin >> extAux;    
        cin >> sizeAux;
        if (extAux.compare(0, 1, "T") == 0) {
            fileList.push_back(make_tuple(descAux, 0, sizeAux));
        }
        else if (extAux.compare(0, 1, "O") == 0) {
            fileList.push_back(make_tuple(descAux, 1, sizeAux));
        }
        else {
            fileList.push_back(make_tuple(descAux, 2, sizeAux));
        }
    }

    sort(fileList.begin(), fileList.end(), sortbyth);

    ll index = 0;
    ll freeSpace = 0;
    for (auto i : fileList) {
        freeSpace += get<2>(i);
        //cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << '\n';
        index++;
        if (index >= del) {
            break;
        }
    }
    
    cout << freeSpace << '\n';

}