#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    vector<int> lines(n);
    vector<vector<int>> parab(m, vector<int>(3));

    for (int i = 0; i < n; i++)
        cin >> lines[i];

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> parab[i][0] >> parab[i][1] >> parab[i][2];
    }    
    // x^2-2x-1

    for (int p = 0; p < m; p++) {
        int a{parab[p][0]}, b{parab[p][1]}, c{parab[p][2]};
        bool got = false;

        for (int l = 0; l < n; l++) {
            b-= lines[l];
            int det = (b*b)-(4*a*c);

            if (det) {
                got = true;
                cout << "YES\n";
                cout << lines[l] << '\n';
                break;
            }
        }
        
        if(!got)
            cout << "NO\n";
    }

    cout << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}