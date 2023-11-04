#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int N; cin >> N;
        vector<int> nums = vector<int>(N+1, 0);
        for (int j = 2; j <= N/2; j++) {
            int k = j;
            while (k <= N) {
                if (!nums[k]) {
                    cout << k << ' ';
                    nums[k] = 1;
                }
                k*= 2;
            }
        }

        for (int j = 1; j <= N; j++) {
            if (!nums[j]) cout << j << ' ';
        }
        cout << '\n';

    }
}