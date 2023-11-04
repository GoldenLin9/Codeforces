#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    int ans = 0;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> diff(n);
    bool worked = false;

    for (int ans = 0; ans <= 2<<7; ans++) {

        for (int i = 0; i < n; i++)
            diff[i] = nums[i]^ans;
        
        int got = diff[0];
        for (int i =1; i < n; i++)
            got^= diff[i];
        
        if (got == 0) {
            worked = true;
            cout << ans << '\n';
            break;
        }
    }

    if (!worked)
        cout << -1<< '\n';
    

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}