#include <bits/stdc++.h>
using namespace std;

long long x, d;

bool beauty(long long n) {
    if (n % d != 0) return false;

    for (long long g = d; g * g <= n; g+= d) {
        if (n % g != 0) continue;

        long long og = n/g;
        if (og % d == 0) return false;
    }
    return true;
}


void solve() {
    cin >> x >> d;
    long long forbid = d/x;

    for (long long n = d+1; n <= x; n++) {
        if (x % n != 0) continue;
        printf("considering %d\n", n);

        long long o = x/n;
        if (beauty(n) and beauty(o)) {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}