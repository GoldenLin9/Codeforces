#include <bits/stdc++.h>
using namespace std;

int n;
long long c;
vector<long long> s;
long long check(long long cw) {
    long long cc{};
    for (int i = 0; i < n; i++) {
        cc+= (s[i] + cw) * (s[i] + cw);
        cc = min(cc, c+1);
    }
    return cc;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> c;
        s = vector<long long>(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        long long hi = 1'000'000'000;
        long long lo = 0;


        while (lo <= hi) {
            
            long long mid = (lo+hi)/2;
            long long val = check(mid);
            if (val == c) {
                cout << mid/2 << '\n';
                break;
            } else if (val < c) lo = mid + 1;
            else if (val > c) hi = mid - 1;
        }
    }
}