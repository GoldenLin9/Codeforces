#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;
vector<int> b;

void solve() {
    cin >> N;
    a = vector<int>(N);
    b = vector<int>(N);
    for (int& n: a) cin >> n;
    for (int& n: b) cin >> n;

    // a[u] - a[v] >= b[u] - b[v]
    // a[u] - b[u] >= a[v] - b[v] for all v

    int m{int(-2e9)};
    for (int i = 0; i < N; i++) m = max(m, a[i] - b[i]);

    vector<int> strong;
    for (int i = 0; i < N; i++) if (a[i] - b[i] >= m) strong.emplace_back(i+1);
    
    cout << strong.size() << '\n';
    for (int i = 0; i < strong.size(); i++) cout << strong[i] << " \n"[i == strong.size()-1];
}



int main() {
    int t; cin >> t;
    while (t--) solve();
}