#include <bits/stdc++.h>
using namespace std;


int colors[200005];
int dp[200005];
int N, K;


bool poss(int i, int k, int c) {

    bool take false;
    bool leave = false;

    if (colors[i] == c or c == -1 or k == 0) {
        if (k == 0) take = poss(i+1, k)
    }

}


void solve() {
    cin >> N >> K;
    for (int i = 0; i < N ;i++) {
        cin >> colors[i];
        dp[i] = -1;
    }
    cout << poss(0, K, -1);
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}