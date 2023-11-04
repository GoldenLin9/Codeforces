#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N; cin >> N;

    vector<int> ac(2*N + 1, 0), bc(2*N + 1, 0);
    vector<int> a(N), b(N);

    for (int& n: a) cin >> n;
    for (int& n: b) cin >> n;


    for (int i = 0; i  < N;) {
        int j = i;
        while (j < N and a[j] == a[i]) j++;
        ac[a[i]] = max(ac[a[i]], j - i);
        i = j;
    }

    for (int i = 0; i  < N;) {
        int j = i;
        while (j < N and b[j] == b[i]) j++;
        bc[b[i]] = max(bc[b[i]], j - i);
        i = j;
    }
    
    int best{};
    for (int i = 0; i < 2*N+1; i++) {
        best = max(best, ac[i] + bc[i]);
    }
    cout << best << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}