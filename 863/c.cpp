#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    n--;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    cout << nums[0] << ' ';

    for (int i = 0; i < n-1; i++) {
        cout << min(nums[i], nums[i+1]) << ' ';
    }

    cout << nums[n-1] << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}