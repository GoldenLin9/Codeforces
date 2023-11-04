#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N, K; cin >> N >> K;
    map<int, int> nums;

    vector<int> res(N, -1);
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        nums[d] = i;
    }
    vector<int> b(N);
    for (int& n: b) cin >> n;

    sort(b.begin(), b.end());

    for (int& n: b) cout << n << ' ';
    int i{};
    for (auto& [key, value]: nums) {
        cout << ">> " << value << '\n';
        res[value] = b[i++];
    }

    for (int n: res) cout << n << ' ';
    cout << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}