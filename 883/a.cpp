#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long cuts{};
        while (n--) {
            int a, b; cin >> a >> b;
            if (b < a) cuts++;
        }
        cout << cuts << '\n';
    }
}