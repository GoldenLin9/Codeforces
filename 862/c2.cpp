#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> lines(n);

    for (auto &p: lines) cin >> p;

    sort(begin(lines), end(lines));

    while (m--) {
        long long int a, b, c; cin >> a >> b >> c;

        long long int part{4*a*c};
        int i = lower_bound(begin(lines), end(lines), b) - begin(lines);
        bool works = false;
        int ans;

        for (int adj = -1; adj <= 0; adj++) {
            
            int mi = i + adj;
            if (mi < 0 || mi >= n) continue;

            long long mb = b - lines[mi];
            if (mb*mb - part < 0) {
                works = true;
                ans = lines[mi];
            }
        }

        if (works) {
            cout << "YES\n";
            cout << ans << '\n';
        } else {
            cout << "NO\n";
        }

        cout << '\n';
    }
}



int main() {
    int t; cin >> t;
    while (t--) solve();
}