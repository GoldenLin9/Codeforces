#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    
    vector<pair<long long, long long>> nums;
    long long alt{};
    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        pair<long long, long long> s;
        vector<long long> m;
        for (int j = 0; j < M; j++) {
            long long d; cin >> d;
            m.push_back(d);
        }
        sort(m.begin(), m.end());
        s.first = m[0];
        s.second = m[1];
        nums.push_back(s);
        alt+= m[0];
    }

    if (N == 1) {
        cout << alt << '\n';
        return;
    }

    sort(nums.begin(), nums.end(), [](auto a, auto b) {
        return a.second >= b.second;
    });

    long long xiao{int(1e9)}, S{};
    for (int i = 0; i < N; i++) {
        if (i != N - 1) S+= nums[i].second;
        xiao = min(xiao, nums[i].first);
    }
    cout << max(S + xiao, alt) << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}