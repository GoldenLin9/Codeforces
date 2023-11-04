#include <bits/stdc++.h>
using namespace std;

int O, N, M;
vector<vector<int>> cyl;
vector<vector<vector<int>>> dp;
int find(int o, int n, int i) {
    if (o <= 0 and n <= 0) return 0;
    if (i >= M) return int(1e9);
    if (dp[o][n][i] != -1) return dp[o][n][i];
    return dp[o][n][i] = min(cyl[i][2] + find(max(0, o - cyl[i][0]), max(0, n - cyl[i][1]), i + 1), find(o, n, i + 1));
}

int main() {
    cin >> O >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        cyl.push_back({a, b, c});
    }

    dp = vector<vector<vector<int>>>(O+1, vector<vector<int>>(N+1, vector<int>(M, -1)));
    for (int o = 0; o <= O; o++)
        for (int n = 0; n <= N; n++)
            dp[o][n][0] = find(o, n, 0);
    cout << dp[O][N][0] << '\n';
}