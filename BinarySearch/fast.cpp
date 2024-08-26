#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> nums;

int K;

int cl(int num) {
    int lo = 0;
    int hi = N - 1;
    int ans = N;

    while (lo <= hi) {
        int m = lo + (hi - lo + 1)/2;

        if (nums[m] > num) {
            ans = m;
            hi = m - 1;
        } else lo = m + 1;
    }

    return ans - 1;
}

int main() {
    cin >> N; 
    nums = vector<int>(N);
    for (int &n: nums) cin >> n;
    sort(nums.begin(), nums.end());
    cin >> K;
    for (int k = 0; k < K; k++) {
        int l, r; cin >> l >> r;
        cout << cl(r) << ' ' << cl(l) << '\n';
        cout << "<<" << (cl(r) - cl(l)) + 1 << '\n';
    }
}