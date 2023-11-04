#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    int last; cin >> last;
    int first = last;

    int ups{}, downs{};
    int san{};

    for (int i = 0; i < n-1; i++) {
        int curr; cin>> curr;
        if (curr > last) {
            ups++;
            san -= curr-last;
        } else if (last > curr) downs ++;
        last = curr;
    }

    printf("up: %d downs: %d\n", ups, downs);
    if (first <= san || ups >= downs) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}