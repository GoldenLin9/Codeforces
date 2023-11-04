#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;

    int last; cin >> last;
    int ans[n];

    last = (last == 1) ? 2: last;
    ans[0] = last;

    for (int i = 1; i < n; i++) {
        int d; cin >> d;

        if (d % last != 0) {

            if (d == 1)
                while (++d % last == 0);

            ans[i] = d;
            last = d;

        } else {
            // modify digit
            ans[i] = d + 1;
            last = d + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}