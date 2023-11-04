#include <bits/stdc++.h>
using namespace std;

long long MOD{(long long)2<<32};

struct M {
    vector<vector<long long>> grid = vector<vector<long long>>(64, vector<long long>(64, 0));

    M operator * (const M& other) {
        M res;
        for (int i = 0; i < 64; i++)
            for (int j = 0; j < 64; j++)
                for (int k = 0; k < 64; k++)
                    res.grid[i][k] += (grid[i][j] * other.grid[j][k]) % MOD;
        return res;
    }
};


int dc[9] = {0, 1, 2, -1,  -2,  -1,  -2,  1, 2};
int dr[9] = {0, -2,  -2,  -2,  -2,  2, 1, 2, 1};

int main() {
    int K; cin >> K;
    M single;

    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)

            for (int d = 0; d < 9; d++) {
                int nr{r + dr[d]}, nc{c + dc[d]};
                if (nr >= 0 and nr < 8 and nc >= 0 and nc < 8) {
                    single.grid[r*8 + c][nr*8 + nc]++;
                    // single.grid[nr*8 + nc][r*8 + c]++;
                }
            }

    M res;
    // for (int i = 0; i < 64; i++) res.grid[i][i]++;
    res.grid[0][0] = 1;

    for (int i = 0; i < K; i++) res = res * single;

    for (int r = 0; r < 64; r++)
        for (int c = 0; c < 64; c++)
            cout << res.grid[r][c] << " \n"[c == 63];

    long long paths{};
    for (int r = 0; r < 64; r++)
        for (int c = 0; c < 64; c++)
            paths+= res.grid[r][c];
    
    cout << paths << '\n';
}