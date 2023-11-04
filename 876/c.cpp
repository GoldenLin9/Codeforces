#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N; cin >> N;
    vector<int> nums(N);
    for (int &n: nums) cin >> n;
    if (nums.back() == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i{N-1}, j{-1}; i >= 0; i--) {
        if (i > 0 and j == -1 and nums[i-1] == 1) {
            j = i;
            continue;
        }
        if (j!= -1 and (i == 0 or nums[i-1] == 0)) {
            int k = j - i;
            while (k--) cout << 0 << ' ';
            cout << j-i << " \n"[i == 0];
            j = - 1;
            continue;
        }
        // prob break test if starts with 0
        // cout << ">>"<<i << ' ';
        if (j == -1) cout << 0 << ' ';
        // cout << "j is " << j << '\n';
    }

}


int main() {
    int t; cin >> t;
    while (t--) solve();
}