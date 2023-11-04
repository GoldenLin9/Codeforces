#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long int n, k; cin >> n >> k;

    if ((n % 2 == 0) || (n % 2 == 1 && ( (k % 2 == 1 && k <= n))))
        cout << "YES\n";
    else
        cout << "NO\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}