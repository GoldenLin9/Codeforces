#include <bits/stdc++.h>
using namespace std;

vector<bool> used;
vector<vector<int>> matrix;
int n;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};


bool good(int r, int c) {
    if (r >= 0 && r < n && c >= 0 && c < n)
        return true;
    return false;
}


bool check() {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (good(nr, nc) && abs(matrix[nr][nc] - matrix[r][c]) == 1)
                    return false;
            }
        }
    }

    return true;
}


bool gen() {
    int row = 0;
    int num = 1;
    bool left;

    while (num < n*n+1) {
        if (num == 1) {
            int r = 0;
            int c = 0;

            while (good(r, c))
                matrix[r++][c++] = num++;

        } else {
            // do left
            int sr = 0;
            int sc = 0;

            int lr = sr + row;
            int lc = sc;
            while (good(lr, lc))
                matrix[lr++][lc++] = num++;
            

            int rr = sr;
            int rc = sc + row;
            while (good(rr, rc))
                matrix[rr++][rc++] = num++;
            
        }
        row++;
    }

    bool works = check();
    if (works) {
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                cout << matrix[r][c] << " \n"[c==n-1];
        return true;
    }

    return false;
}


void solve() {
    cin >> n;
    used = vector<bool>(n*n+1);
    matrix = vector<vector<int>>(n, vector<int>(n));

    bool got = gen();
    if (!got) cout << -1 << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}