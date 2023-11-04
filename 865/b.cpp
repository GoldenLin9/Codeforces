#include <bits/stdc++.h>
using namespace std;


int n;

bool good(int r, int c) {
    if (c < n) return true;
    return false;
}


void solve() {
    cin >> n;

    vector<vector<int>> grid(2, vector<int>(n, -1));

    int num = 2*n;
    int num2 = n;

    grid[1][n-1] = num;
    num--;

    int cr{}, cc{};

    while (good(cr, cc)) {
        if (grid[cr][cc] == -1) {
            grid[cr][cc] = num--;
            cr = (cr == 0) ? 1: 0;
        }
        cc++;
    }

    int ccr{1}, ccc{};
    while (good(ccr, ccc)) {
        grid[ccr][ccc] = num2--;
        ccr = (ccr == 0) ? 1: 0;
        ccc++;
    }

    for (int r = 0; r < 2; r++)
        for (int c = 0; c < n; c++)
            cout << grid[r][c] << " \n"[c == n-1];
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}