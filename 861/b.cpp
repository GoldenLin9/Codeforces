#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<long long int>> cards(m, vector<long long int>(n));
    vector<long long int> sums(m);

    for (int c = 0; c < n; c++) 
        for (int r = 0; r < m; r++) {
            int d; cin >> d;
            cards[r][c] = d;

            sums[r] += d;
        }
    
    
    for (int i = 0; i < m; i++)
        sort(begin(cards[i]), end(cards[i]));


    long long int ans{};
    
    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            long long int d{cards[r][c]};
            sums[r] -= d;

            ans += abs((((n-c-1)*d) - sums[r]));
            // printf("added %d\n", abs(((n-c-1*d) - sums[r])));
        }

            
    cout << ans << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}

// 2, 0, 3
// 0000
// 2, 2, 4

//2, 1
// 000
// 0, 6

//3
// 6


// 2, 3, 2, 1, 3 = 11
// |4-8| = 4 + |6-5| = 5 + |1-4| = 8

// 5
// |1 - 3| + |1 - 1| + |1-4| = 5
// |3-1| + |3-1| + |3-7|

// 1 1 3 4
// ans: 2 + 3 + 2 + 1 + 3 = 11
// meth: |3-8| = 5 + |2 - 7| = 10 + 