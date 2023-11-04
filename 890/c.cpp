#include <bits/stdc++.h>
using namespace std;

vector<int> nums;


void solve() {
    int N, K; cin >> N >> K;
    nums = vector<int>(N);
    for (int& num: nums) cin >> num;

    int best{};
    for (int i = 0; i < N; i++) {
        int roundB{nums[i]};
        int used{};
        for (int j = i+1; j < N; j++) {
            int be = nums[j] + (j - i);
            if (K >= (be - nums[i]) + used) {
                roundB = be;
            }

            
            // printf("%d at %d %d with %d used %d\n", best, i, j, currK, canUse);
        }
    }

    cout << best << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}