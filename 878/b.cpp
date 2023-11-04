#include <bits/stdc++.h>
using namespace std;
vector<int> cupcakes(33, 0);


long long ways(long long t, long long i) {
    if (i < 0 or t < 0) return 0;

    long long take{};
    if (cupcakes[i] and t >= (1LL << i))
        take+= 1 + ways(t - (1LL << i), i - 1);
    
    long long leave = ways(t, i-1);

    return take + leave;
}


int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        for (int i = 0; i < 33; i++)
            if (i <= K - 1)
                cupcakes[i] = 1;

        cout << ways(N, 32) + 1 << '\n';
        cupcakes = vector<int>(33, 0);
    }
}