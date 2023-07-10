#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    ll aux1;
    string aux2;
    string aux3;
    
    vector <tuple<string, string>> words;

    // string** matrix = new string*[n];
    // for (ll i =  0; i < n; i++) {
    //     matrix[i] = new string[m];
    // }
    // int** auxM = new int*[n];
    // for (ll i =  0; i < n; i++) {
    //     auxM[i] = new int[m];
    // }
    // string matrix[n][m];
    //int auxM[n][m];

    vector<vector<string>> matrix(n + 2);
    vector<vector<int>> auxM(n + 2);

    for (ll i = 0; i < k; i++) {
        cin >> aux1;
        // cout << aux1 << '\n';
        cin >> aux2;
        cin >> aux3;
        words.push_back(make_tuple(aux2, aux3));
    }

    // for (auto it  = words.begin(); it != words.end(); it++) {
    //     cout << get<0>(*it) << ' ' << get<1>(*it) << '\n';
    // }

    string temp;
    for (ll i = 0; i < n + 2; i++) {
        for (ll c = 0; c < m + 2; c++) {
            if (i == 0 || c == 0 || i == n + 1 || c == m + 1) {
                matrix[i].push_back("00\0");
            }
            else {
                cin >> temp;
                matrix[i].push_back(temp);
            }
            //cin >> matrix[i][c];
            auxM[i].push_back(0);
        }
    }

    int found = 0;
    for (ll i = 1; i < n + 1; i++) {
        for (ll c = 1; c < m + 1; c++) {
            found = 0;
            //if (auxM[i][c] == 0) {                
                for (auto it = words.begin(); it != words.end(); it++) {
                    if (matrix[i][c].compare(0, 2, get<0>(*it)) == 0 && matrix[i][c+1].compare(0, 2, get<1>(*it)) == 0) {
                        found = 1;
                        auxM[i][c] = 1;
                        auxM[i][c + 1] = 1;
                        if (i > 1) {
                            if (c > 1 && c + 1 < m) {
                                if (auxM[i - 1][c - 1] != 1) {
                                    matrix[i - 1][c - 1] = "00\0";
                                }
                                if (auxM[i][c - 1] != 1) {
                                    matrix[i][c - 1] = "00\0";
                                }
                                if (auxM[i - 1][c] != 1) {
                                    matrix[i - 1][c] = "00\0";
                                }
                                if (auxM[i - 1][c + 1] != 1) {
                                    matrix[i - 1][c + 1] = "00\0";
                                }
                                if (auxM[i - 1][c + 2] != 1) {
                                    matrix[i - 1][c + 2] = "00\0";
                                }

                            }
                            else if (c == 1) {
                                if (auxM[i - 1][c] != 1) {
                                    matrix[i - 1][c] = "00\0";
                                }
                                if (auxM[i - 1][c + 1] != 1) {
                                    matrix[i - 1][c + 1] = "00\0";
                                }
                                if (auxM[i - 1][c + 2] != 1) {
                                    matrix[i - 1][c + 2] = "00\0";
                                }
                            }
                            else if (c + 1 == m) {
                                if (auxM[i - 1][c - 1] != 1) {
                                    matrix[i - 1][c - 1] = "00\0";
                                }
                                if (auxM[i][c - 1] != 1) {
                                    matrix[i][c - 1] = "00\0";
                                }
                                if (auxM[i - 1][c] != 1) {
                                    matrix[i - 1][c] = "00\0";
                                }
                                if (auxM[i - 1][c + 1] != 1) {
                                    matrix[i - 1][c + 1] = "00\0";
                                }
                            }                  
                        }
                        else if (i == 1) {
                            if (c > 0 && c + 1 < m) {
                                if (auxM[i][c - 1] != 1) {
                                    matrix[i][c - 1] = "00\0";
                                }

                            }
                            else if (c + 1 == m) {
                                if (auxM[i][c - 1] != 1) {
                                    matrix[i][c - 1] = "00\0";
                                }
                            } 
                        }
                    }                
                }

                if (i > 1 && found == 0 && auxM[i][c] != 1) {
                    if (c > 1 && c < m) {
                        if (auxM[i - 1][c] == 1 || auxM[i][c - 1] == 1 || auxM[i - 1][c - 1] == 1 || auxM[i-1][c+1] == 1) {
                            matrix[i][c] = "00\0";
                        }
                    }
                    else if (c == 1) {
                        if (auxM[i - 1][c] == 1 || auxM[i][c + 1] == 1 || auxM[i-1][c+1] == 1) {
                            matrix[i][c] = "00\0";
                        }
                    }
                    else if (c == m) {
                        if (auxM[i - 1][c] == 1 || auxM[i][c - 1] == 1 || auxM[i - 1][c - 1] == 1) {
                            matrix[i][c] = "00\0";
                        }
                    }
                }
                else if (i == 1 && found == 0 && auxM[i][c] != 1) {
                    if (c > 1 && c < m) {
                        if (auxM[i][c - 1] == 1) {
                            matrix[i][c] = "00\0";
                        }
                    }
                    else if (c == m) {
                        if ((auxM[i][c - 1] == 1)) {
                            matrix[i][c] = "00\0";
                        }
                    }
                }
           /// }
        }
    }

    for (ll i = 1; i < n + 1; i++) {
        for (ll c = 1; c < m + 1; c++) {
            cout << matrix[i][c] << ' ';
        }
        cout << '\n';
    }

    // for (ll i = 1; i < n + 2; i++) {
    //     for (ll c = 1; c < m + 2; c++) {
    //         cout << auxM[i][c] << ' ';
    //     }
    //     cout << '\n';
    // }
    
}