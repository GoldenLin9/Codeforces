#include <bits/stdc++.h>
using namespace std;


int diff(int first, int second, int k) {
    if (k == 0) return second;
    return diff(second, first+second, k-1);
}


int check(int first, int second, int k) {
    if (second < first) return -1;
    if (first < 0) return -1;
    if (k == 0) return first;
    return check(second-first, first, k-1);
}


void solve() {
    int n, k; cin >> n >> k;
    int d = diff(1, 1, k-3);
    
    int works{};
    for (int t = n; t >= 0; t--) {
        int val = check(n-t, t, k-3);
        if (val >= 0) works+= 1;
        // if (val >= 0) {
        //     if (val) works = (val/d)+1;
        //     else works = 1;
        //     break;
        // }
    }

    cout << works << '\n';
}


int main() {
    int N; cin >> N;
    while (N--) solve();
}