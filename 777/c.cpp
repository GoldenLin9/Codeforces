#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));

    int count{};
    for (int r = 0; r < N; r++) {
        string s; cin >> s;
        for (int c = 0;c < M; c++) {
            int d = s[c] - '0';
            if (d) count++;
            grid[r][c] = d;
        }
    }

    if (grid[0][0]) {
        cout << -1 << '\n';
        return;
    }

    cout << count << '\n';
    for (int r = 0; r < N; r++)
        for (int c = M-1; c > 0; c--) {
            if (grid[r][c]) {
                printf("%d %d %d %d\n", r+1, c, r+1, c+1);
            }
        }
    
    for (int r = N-1; r > 0; r--)
        if (grid[r][0]) printf("%d %d %d %d\n", r, 1, r+1, 1);
    
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}