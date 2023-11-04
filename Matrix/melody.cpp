#include <bits/stdc++.h>
using namespace std;

int N, D, K, S;
long long MOD = {int(1e9) + 7};

struct M {
    long long grid[101][101] = {};
    M operator* (const M& other) {
        M res;
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
                for (int k = 0; k <= 100; k++)
                    res.grid[i][k] = (res.grid[i][k] + (grid[i][j] * other.grid[j][k])) % MOD;
        return res;
    }
};

M expo(M base, int K) {
    M res; res.grid[S-1][S-1] = 1;
    while (K) {
        if (K&1) res = res * base;
        base = base * base;
        K>>=1;
    }
    return res;
}

int main() {
    cin >> N >> D >> K >> S;

    M base;
    for (int n = 0; n < N; n++)
        for (int x = n - D; x <= n + D; x++)
            base.grid[n][(x+N) % N] = 1;
    for (int i = 0; i <= 100; i++) base.grid[i][100] = 1;

    cout << expo(base, K).grid[S-1][100] << '\n';
}