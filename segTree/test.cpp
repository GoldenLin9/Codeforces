#include <bits/stdc++.h>
using namespace std;


struct M {
    int m[2][2] = {{1, 0}, {0, 1}};

    M operator * (const M& other) {
        M res;
        for (int rc = 0; rc < 2; rc++)
            for (int lc = 0; lc < 2; lc++)
                for (int lr = 0; lr < 2; lr++)
                    res.m[rc][lr]+= (m[rc][lc] * other.m[lc][lr]);
        return res;
    }
};

int main() {
    cout << (long long) 1e10 * 10000;
}