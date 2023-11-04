#include <bits/stdc++.h>
using namespace std;


int find(long long a, long long b) {
    int lo = 0;
    int hi = 31;

    while (lo != hi) {
        int mid = (lo + hi)/2;
        if ((a << mid) >= b) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}



void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int &n: nums) cin >> n;

    long long cnt{};

    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            int power = find((long long) nums[i], (long long) nums[i-1]);
            nums[i] = nums[i] << power;
            cnt+= power;
        }
    }

    cout << cnt << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}