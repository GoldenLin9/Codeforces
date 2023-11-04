#include <bits/stdc++.h>
using namespace std;
 
 
long long MOD = int(1e9) + 7;
int N;
 
struct M {
    long long arr[100][100] = {};
    M operator * (const M& other) {
        M res;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                for (int k = 0; k < 100; k++)
                    res.arr[i][k] = ((res.arr[i][k] % MOD) + ((arr[i][j] * other.arr[j][k]) % MOD)) % MOD;
        return res;
    }
};
 
 
M expo(M single, int K) {
    M res;
    for (int i = 0; i < N; i++) res.arr[i][i] = 1;
 
    while (K > 0) {
        if (K % 2) res = res * single;
        single = single * single;
        K/= 2;
    }
 
    return res;
}
 
 
int main() {
    cin >> N;
    int Edges; cin >> Edges;
    int K; cin >> K;
 
    M single;
    for (int i = 0; i < Edges; i++) {
        int a, b; cin >> a >> b;
        single.arr[a-1][b-1] = 1;
    }
 
    M res = expo(single, K);
    long long paths{};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << res.arr[i][j] << " \n"[j == N-1];
    cout << paths << '\n';
    
}