#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s; cin >> s;

    for (int i = s.size()-2; i >= 0; i--) {
        int a{s[i]-'0'};
        int b{s[i+1]-'0'};

        int digits = to_string(a+b).size();
        if (digits == 2) {
            cout << s.substr(0, i) << a+b << s.substr( i + 2 >= s.size() ? s.size(): i + 2, s.size()) << '\n';
            return;
        }
    }
    cout << (s[0]-'0') + (s[1]-'0') << s.substr( 2 >= s.size() ? s.size(): 2, s.size()) << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}