#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int cs = 1; cs <= n; cs++) {
        int m;
        cin >> m;

        vector<int> pellets(m);

        for (int i = 0; i < m; i++) cin >> pellets[i];

        vector<int> lis(m, 1), lds(m, 1);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < i; j++)
                if (pellets[i] >= pellets[j])
                    lis[i] = max(lis[i], lis[j] + 1);
        
        for (int i = m - 1; i >= 0; i--)
            for (int j = m - 1; j > i; j--)
                if (pellets[i] >= pellets[j])
                    lds[i] = max(lds[i], lds[j] + 1);
        
        int ans = 0;

        for (int i = 0; i < m; i++)
            ans = max(ans, lis[i] + lds[i] - 1);

        printf("Case %d:\nDynamo ate %d food pellet(s).\n\n", cs, ans);
    }
}