#include <bits/stdc++.h>
using namespace std;
int main() {
int x = 5;
int y = 10;
int floor1 = x/y;
int ceil1 = (x+y-1)/y;
int ceil2 = x/y + bool(x%y);
int nextup = x+y-1 - (x+y-1)%y;
int nextdw = x - (x%y);
cout << nextdw << '\n';
cout << nextup << '\n';
}