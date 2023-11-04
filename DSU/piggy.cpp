#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 1e10;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int e, f;
        cin >> e >> f;

        int w = f - e;

        int n;
        cin >> n;
        
        vector<ll> value(n), weight(n), dp(w + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) cin >> value[i] >> weight[i];
        
        for (int coin = 0; coin < n; coin++)
            for (int i = 0; i + weight[coin] <= w; i++)
                if (dp[i] != INF)
                    dp[i + weight[coin]] = min(dp[i + weight[coin]], dp[i] + value[coin]);
        
        if (dp[w] != INF) printf("The minimum amount of money in the piggy-bank is %lld.\n", dp[w]);
        else printf("This is impossible.\n");
    }
}