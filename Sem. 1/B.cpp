#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    
    ll height;
    char direction;

    vector <tuple<ll, char>> towers;

    for (ll i = 0; i < t; i++) {
        cin >> height;
        cin >> direction;
        towers.push_back(make_tuple(height, direction));
    }

    auto it = towers.begin();
    //auto aux = towers.begin();
    int failed = 0;
    //int found;
    while(it != towers.end()) {
        // for (auto k : towers) {
        //     cout << get<0>(k) << ' ';
        // }
        // cout << '\n';
        if (get<0>(*it) != -1) {
            //cout << h.size() << '\n';
            // found = 0;
            // if (it == towers.begin()) {
            //     if (get<1>(*it) == 'O') {
            //         cout << "N\n";
            //         failed = 1;
            //         break;
            //     }
            //     //cout << *itB << ' ' << *auxD;
            //     *aux = *it;
            // }
            // else {
            auto aux = it;
            aux++;
            while (aux != towers.end()) {
                if (get<0>(*aux) != -1) {
                    if (get<0>(*aux) > get<0>(*it) || (get<0>(*it) == get<0>(*aux) && get<1>(*it) == get<1>(*aux)) || (get<0>(*it) == get<0>(*aux) && get<1>(*it) == 'O' && get<1>(*aux) == 'L')) {
                        // cout << get<0>(*it) << ' ' << get<1>(*it) << '\n'; 
                        // cout << get<0>(*aux) << ' ' << get<1>(*aux) << '\n';  
                        cout << "N\n";
                        failed = 1;
                        break;
                    }
                    else if (get<0>(*it) == get<0>(*aux) && get<1>(*it) == 'L' && get<1>(*aux) == 'O') {
                        get<0>(*it) = -1;
                        get<0>(*aux) = -1;
                        break;
                    }
                }

                if (aux != towers.end()) {
                    aux++;
                }            
            }
            if (failed == 1) {
                break;
            }
                // else if (get<0>(*it) == get<0>(*aux) && get<1>(*it) != get<1>(*aux)) {
                //     //towers.erase(it);
                //     //towers.erase(aux);
                //     //it = towers.begin();
                //     if (get<1>(*it) == 'O') {
                //         cout << "N\n";
                //         failed = 1;
                //         break;
                //     }
                //     aux = towers.begin();
                //     found = 1;
                // }
            //}

            

            //if (found == 0) {

        }

        

        if (it != towers.end()) {
            it++;
        }
        
        //}
    }

    if (failed == 0) {
        cout << "S\n";
    }
}