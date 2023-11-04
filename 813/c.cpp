#include <bits/stdc++.h>
using namespace std;


vector<int> nums, bien, saw, uniques, seen;
int solve() {
    int N; cin >> N;
    nums = vector<int>(N);
    uniques = vector<int>(N);
    bien = vector<int>(int(1e5) + 5, 0);
    seen = vector<int>(int(1e5) + 5, 0);
    set<int> uni;
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        uni.emplace(d);
        uniques[i] = uni.size();
        nums[i] = d;
    }

    int jzong{}, zong{};

    int cp{-1};
    for (int i = N - 1; i > 0; i--) {
        if (nums[i] >= nums[i-1]) {
            seen[nums[i]] = i;
        } else {
            cp = i - 1;
            break;
        }
    }

    if (cp != -1) {
        while (cp >= 0) {
            if (seen[nums[cp]])
                jzong = max(jzong, uniques[seen[nums[cp]]]);
            else {
                if (!bien[nums[cp]]) {
                    bien[nums[cp]] = 1;
                    zong++;
                }
            }
            cp--;
        }
        return max(zong, jzong);
    } else return 0;
}

int main() {
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}