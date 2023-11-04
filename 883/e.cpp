#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> arr;
    cout << arr[0] << '\n';
    for (int k = 2; k < 1'000'000; k++) {
        long long n = 1;
        long long cp = 1;
        while (n <= 1'000'001) {
            arr[n] = 1;
            cp*= k;
            n+= cp;
            // cout << n << '\n';
        }
        // cout << k << '\n';
    }

    cout << "done\n";

    // int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int d; cin >> d;
    //     if (arr[d] == 1) cout << "YES\n";
    //     else cout << "NO\n";
    // }
}