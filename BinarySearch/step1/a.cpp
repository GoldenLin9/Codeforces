#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, K; cin >> N >> K;

    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }


    for (int k = 0; k < K; k++) {
        int q; cin >> q;

        int l = 0;
        int r = N - 1;
        bool ok = false;

        while (l <= r) {

            int m = l + (r - l) /2;

            if (nums[m] == q) {
                ok = true;
                break;
            } else if (nums[m] > q) {
                r = m - 1;
            } else if (nums[m] < q) {
                l = m + 1;
            }

        }

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}