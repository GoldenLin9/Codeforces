#include <bits/stdc++.h>
using namespace std;

int N, got{1};
int a[200000];
int b[200000];
int dp[200000];
int vis[200000];


bool dfs(int u) {
    if (dp[u] or got == N) return true;
    for (int v = 0; v < N; v++) {
        if (not vis[v] and a[u] - a[v] >= b[u] - b[v]) {
            vis[v] = true;
            got++;
            if (dfs(v)) return true;
        }
    }
    return false;
}


void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    for (int i = 0; i < N; i++) dp[i] = vis[i] = false;

    vector<int> strong;
    for (int n = 0; n < N; n++) {
        for (int i = 0; i < N; i++) {
            vis[i] = false;
            if (n != i and dp[i] and a[i] - a[n] >= b[i] - b[n]) {
                strong.emplace_back(n+1);
                dp[n] = true;
                break;
            }
        }
        if (dp[n]) continue;
        vis[n] = true;
        if (dp[n] = dfs(n)) strong.emplace_back(n+1);
        got = 1;
    }

    cout << strong.size() << '\n';
    for (int i = 0; i < strong.size(); i++) cout << strong[i] << " \n"[i == strong.size()-1];
}



int main() {
    int t; cin >> t;
    while (t--) solve();
}