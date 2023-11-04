#include <bits/stdc++.h>
using namespace std;

long long MOD{1000000007};


struct Matrix {
    int arr[2][2] = {};
    Matrix operator * (const Matrix& other) {
        Matrix res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    res.arr[i][j] += (arr[i][j] * other.arr[j][k]) % MOD;
        return res;
    }
}


int main() {
    long long N; cin >> N;
    Matrix res;
    res.arr[0][0] = 0;
    res.arr[1][1] = 1;

    Matrix single;
    single.arr[0][0] = 0;
    single.arr[0][1] = single.arr[1][1];
    single.arr[1][1] = single.arr[1][1];



    // vector<long long> prev = {0, 1};

    // for (int i = 0; i < N; i++) {
    //     long long a = prev[0]*0 + prev[1]*1;
    //     long long b = (prev[0]*1 + prev[1]) % MOD;

    //     prev = {a, b};
    //     cout << i << ' ' << prev[0] << ' ' << prev[1] << '\n';
    // }

    // cout << prev[0] << '\n';
}