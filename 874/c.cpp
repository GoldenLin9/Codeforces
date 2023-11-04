#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N; cin >> N;
    vector<int> nums;
    int smallO{int(1e9)};
    for (int n = 0; n < N; n++) {
        int d; cin >> d;
        if (d % 2) smallO = min(d, smallO);
        nums.push_back(d);
    }

    int e{}, o{};
    for (; e < N; e++) if (nums[e] % 2 == 1 and nums[e] - smallO <= 0) break;
    for (; o < N; o++) if (nums[o] % 2 == 0 and nums[o] - smallO <= 0) break;
    if (e == N or o == N) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}