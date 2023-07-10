#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

ll findMaxSubarraySum(vector <ll> &arr, ll n, ll sum) {
    // To store current sum and
    // max sum of subarrays
    ll curr_sum = arr[0], max_sum = 0, start = 0;
 
    // To find max_sum less than sum
    for (ll i = 1; i < n; i++) {
 
        // Update max_sum if it becomes
        // greater than curr_sum
        if (curr_sum <= sum)
            max_sum = max(max_sum, curr_sum);
 
        // If curr_sum becomes greater than
        // sum subtract starting elements of array
        while (start < i && curr_sum + arr[i] > sum) {
            curr_sum -= arr[start];
            start++;
        }
 
        // If cur_sum becomes negative then start new subarray
        if (curr_sum < 0) {
            curr_sum = 0;
        }
 
        // Add elements to curr_sum
        curr_sum += arr[i];
 
    }
 
    // Adding an extra check for last subarray
    if (curr_sum <= sum)
        max_sum = max(max_sum, curr_sum);
 
    return max_sum;
}

int main() {
    ll n;
    ll m;

    cin >> n;
    cin >> m;

    vector<ll> v(n);
    for (ll& el : v) { 
        cin >> el; 
    }

    cout << findMaxSubarraySum(v, n, m) << '\n';
    return 0;
}