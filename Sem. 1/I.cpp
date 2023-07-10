#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void split(string &str, char delim, vector<string> &out) {
	ll start;
	ll end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos) {
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

int main() {
    ll n;
    cin >> n;

    ll r = 4;
    ll w = 2;
    ll x = 1;

    string oct;
    vector <string> argList;
    char d;
    ll t;
    string aux;

    vector <string> temp;
    for (ll i = 0; i < n; i++) {   
        cin >> oct;
        cin >> t;
        cin >> aux;
        split(aux, ',', argList);
        for (auto it : argList) {
            ll num = 0;
            ll all = 0;
            char del;
            if (it.find('+') != string::npos) {
                split(it, '+', temp);
                del = '+';
            }
            else if (it.find('-') != string::npos) {
                split(it, '-', temp);
                del = '-';
            }
            else if (it.find('=') != string::npos) {
                split(it, '=', temp);
                del = '=';
            }
            aux = temp[0];

            for (ll k = 0; k < aux.length(); k++) {
                char tmp = aux[k];
                if (temp[1].find('r') != string::npos) {
                    num = r;
                    if (all != 7 && all != 5 && all != 6 && all != 4) {
                        all += r;
                    }

                    if (tmp == 'u') {
                        if (del == '+') {
                            if (oct[0] - 48 != 7 && oct[0] - 48 != 5 && oct[0] - 48 != 6 && oct[0] - 48 != 4) {
                                oct[0] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[0] - 48 == 7 || oct[0] - 48 == 4 || oct[0] - 48 == 6 || oct[0] - 48 == 5) {
                                oct[0] -= num;
                            }
                        }
                        else if (del == '=') {
                            oct[0] = all + 48;
                        }
                    }
                    else if (tmp == 'g') {
                        if (del == '+') {
                            if (oct[1] - 48 != 7 && oct[1] - 48 != 5 && oct[1] - 48 != 6  && oct[1] - 48 != 4) {
                                oct[1] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[1] - 48 == 7 || oct[1] - 48 == 4 || oct[1] - 48 == 6 || oct[1] - 48 == 5) {
                                oct[1] -= num;
                            }
                        }
                        else if (del == '=') {
                            oct[1] = all + 48;
                        }
                    }
                    else if (tmp == 'o') {
                        if (del == '+') {
                            if (oct[2] - 48 != 7 && oct[2] - 48 != 5 && oct[2] - 48 != 6  && oct[2] - 48 != 4) {
                                oct[2] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[2] - 48 == 7 || oct[2] - 48 == 4 || oct[2] - 48 == 6 || oct[2] - 48 == 5) {
                                oct[2] -= num;
                            }
                        }
                        else if (del == '=') {                        
                            oct[2] = all + 48;
                        }
                    }
                    else if (tmp == 'a') {
                        if (del == '+') {
                            if (oct[0] - 48 != 7 && oct[0] - 48 != 5 && oct[0] - 48 != 6  && oct[0] - 48 != 4) {
                                oct[0] += num;
                            }
                            if (oct[1] - 48 != 7 && oct[1] - 48 != 5 && oct[1] - 48 != 6  && oct[1] - 48 != 4) {
                                oct[1] += num;
                            }
                            if (oct[2] - 48 != 7 && oct[2] - 48 != 5 && oct[2] - 48 != 6  && oct[2] - 48 != 4) {
                                oct[2] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[0] - 48 == 7 || oct[0] - 48 == 4 || oct[0] - 48 == 6 || oct[0] - 48 == 5) {
                                oct[0] -= num;
                            }
                            if (oct[1] - 48 == 7 || oct[1] - 48 == 4 || oct[1] - 48 == 6 || oct[1] - 48 == 5) {
                                oct[1] -= num;
                            }
                            if (oct[2] - 48 == 7 || oct[2] - 48 == 4 || oct[2] - 48 == 6 || oct[2] - 48 == 5) {
                                oct[2] -= num;
                            }
                        }
                        else if (del == '=') {
                            oct[0] = all + 48;
                            oct[1] = all + 48;
                            oct[2] = all + 48;
                        }
                    }

                }
                if (temp[1].find('x') != string::npos) {
                    num = x;
                    if (all != 1 && all != 3 && all != 5 && all != 7) {
                        all += x;
                    }

                    if (tmp == 'u') {
                        if (del == '+') {
                            if (oct[0] - 48 != 1 && oct[0] - 48 != 5 && oct[0] - 48 != 3 && oct[0] - 48 != 7) {
                                oct[0] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[0] - 48 == 1 || oct[0] - 48 == 5 || oct[0] - 48 == 3 || oct[0] - 48 == 7) {
                                oct[0] -= num;
                            }
                        }
                        else if (del == '=') {
                            oct[0] = all + 48;
                        }
                    }
                    else if (tmp == 'g') {
                        if (del == '+') {
                            if (oct[1] - 48 != 1 && oct[1] - 48 != 5 && oct[1] - 48 != 3 && oct[1] - 48 != 7) {
                                oct[1] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[1] - 48 == 1 || oct[1] - 48 == 5 || oct[1] - 48 == 3 || oct[1] - 48 == 7) {
                                oct[1] -= num;
                            }
                        }
                        else if (del == '=') {
                            oct[1] = all + 48;
                        }
                    }
                    else if (tmp == 'o') {
                        if (del == '+') {
                            if (oct[2] - 48 != 1 && oct[2] - 48 != 5 && oct[2] - 48 != 3 && oct[2] - 48 != 7) {
                                oct[2] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[2] - 48 == 1 || oct[2] - 48 == 5 || oct[2] - 48 == 3 || oct[2] - 48 == 7) {
                                oct[2] -= num;
                            }
                        }
                        else if (del == '=') {
                            oct[2] = all + 48;
                        }
                    }
                    else if (tmp == 'a') {
                        if (del == '+') {
                            if (oct[0] - 48 != 1 && oct[0] - 48 != 5 && oct[0] - 48 != 3  && oct[0] - 48 != 7) {
                                oct[0] += num;
                            }
                            if (oct[1] - 48 != 1 && oct[1] - 48 != 5 && oct[1] - 48 != 3  && oct[1] - 48 != 7) {
                                oct[1] += num;
                            }
                            if (oct[2] - 48 != 1 && oct[2] - 48 != 5 && oct[2] - 48 != 3  && oct[2] - 48 != 7) {
                                oct[2] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[0] - 48 == 1 || oct[0] - 48 == 5 || oct[0] - 48 == 3 || oct[0] - 48 == 7) {
                                oct[0] -= num;
                            }
                            if (oct[1] - 48 == 1 || oct[1] - 48 == 5 || oct[1] - 48 == 3 || oct[1] - 48 == 7) {
                                oct[1] -= num;
                            }
                            if (oct[2] - 48 == 1 || oct[2] - 48 == 5 || oct[2] - 48 == 3 || oct[2] - 48 == 7) {
                                oct[2] -= num;
                            }
                        }
                        else if (del == '=') {
                            oct[0] = all + 48;
                            oct[1] = all + 48;
                            oct[2] = all + 48;
                        }
                    }

                }
                if (temp[1].find('w') != string::npos) {
                    num = w;
                    if (all != 2 && all != 3 && all != 6 && all != 7) {
                        all += w;
                    }

                    if (tmp == 'u') {
                        if (del == '+') {
                            if (oct[0] - 48 != 2 && oct[0] - 48 != 3 && oct[0] - 48 != 6 && oct[0] - 48 != 7) {
                                oct[0] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[0] - 48 == 2 || oct[0] - 48 == 3 || oct[0] - 48 == 6 || oct[0] - 48 == 7) {
                                oct[0] -= num;
                            }                        
                        }
                        else if (del == '=') {
                            oct[0] = all + 48;
                        }
                    }
                    else if (tmp == 'g') {
                        if (del == '+') {
                            if (oct[1] - 48 != 2 && oct[1] - 48 != 3 && oct[1] - 48 != 6 && oct[1] - 48 != 7) {
                                oct[1] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[1] - 48 == 2 || oct[1] - 48 == 3 || oct[1] - 48 == 6 || oct[1] - 48 == 7) {
                                oct[1] -= num;
                            } 
                        }
                        else if (del == '=') {
                            oct[1] = all + 48;
                        }
                    }
                    else if (tmp == 'o') {
                        if (del == '+') {
                            if (oct[2] - 48 != 2 && oct[2] - 48 != 3 && oct[2] - 48 != 6 && oct[2] - 48 != 7) {
                                oct[2] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[2] - 48 == 2 || oct[2] - 48 == 3 || oct[2] - 48 == 6 || oct[2] - 48 == 7) {
                                oct[2] -= num;
                            } 
                        }
                        else if (del == '=') {
                            oct[2] = all + 48;
                        }
                    }
                    else if (tmp == 'a') {
                        if (del == '+') {
                            if (oct[0] - 48 != 2 && oct[0] - 48 != 3 && oct[0] - 48 != 6 && oct[0] - 48 != 7) {
                                oct[0] += num;
                            }
                            if (oct[1] - 48 != 2 && oct[1] - 48 != 3 && oct[1] - 48 != 6 && oct[1] - 48 != 7) {
                                oct[1] += num;
                            }
                            if (oct[2] - 48 != 2 && oct[2] - 48 != 3 && oct[2] - 48 != 6 && oct[2] - 48 != 7) {
                                oct[2] += num;
                            }
                        }
                        else if (del == '-') {
                            if (oct[0] - 48 == 2 || oct[0] - 48 == 3 || oct[0] - 48 == 6 || oct[0] - 48 == 7) {
                                oct[0] -= num;
                            }
                            if (oct[1] - 48 == 2 || oct[1] - 48 == 3 || oct[1] - 48 == 6 || oct[1] - 48 == 7) {
                                oct[1] -= num;
                            } 
                            if (oct[2] - 48 == 2 || oct[2] - 48 == 3 || oct[2] - 48 == 6 || oct[2] - 48 == 7) {
                                oct[2] -= num;
                            } 
                        }
                        else if (del == '=') {
                            oct[0] = all + 48;
                            oct[1] = all + 48;
                            oct[2] = all + 48;
                        }
                    }
                }
            }
            temp.clear();
        }
        argList.clear();

        cout << oct << '\n';
    }
    
}