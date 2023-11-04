#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> costs;
vector<int> have;
vector<vector<int>> req;


void solve() {
    cin >> N >> K;
    costs = vector<int>(N);
    have = vector<int>(K, 0);
    req = vector<vector<int>>(N);
    for (int i = 0; i < N; i++) cin >> costs[i];
    for (int i = 0; i < K; i++) cin >> have[i];

    for (int i = 0; i < N; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int d; cin >> d;
            req[i].push_back(d);
        }
    }

    long long tc{};
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            bool good = true;
            for (int j = 0; j < req[i].size(); j++) {
                if (not have[req[i][j]]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                have[i] = 1;
            }
            tc+= costs[i];
        }
    }

    cout << tc << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}