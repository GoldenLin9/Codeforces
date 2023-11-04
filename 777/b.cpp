#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> grid(N + 2, vector<int>(M + 2, 0));
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int r = 1; r < N+1; r++) {
        string s; cin >> s;
        for (int c = 1; c < M+1; c++) {
            grid[r][c] = s[c-1] - '0';
        }
    }


    for (int r = 1; r < N + 1; r++)
        for (int c = 1; c < M + 1; c++) {
            if (grid[r][c] == 0) {
                for (int d = 0; d < 8; d+= 2)
                    if (grid[r+dr[d]][c+dc[d]] == 1 and grid[r+dr[(d+1) % 8]][c+dc[(d+1) % 8]] == 1 and grid[r+dr[(d+2) % 8]][c+dc[(d+2) % 8]] == 1) {
                        cout << "NO\n";
                        return;
                    }
            }
        }

    cout << "YES\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}