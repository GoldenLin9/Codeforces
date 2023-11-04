#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s; cin >> s;
    vector<int> chrs(26, 0);
    int duo{};

    for (char c: s)
        duo = max(duo, ++chrs[c-'a']);
    
    
    if (duo == s.size()) cout << 0 << '\n';
    else if (s.size()-duo == 1) cout << 1 << '\n';
    else cout << floor(log2(s.size()-duo)) << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}