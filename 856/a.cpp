#include <bits/stdc++.h>
using namespace std;


void solve() {
    cout.flush();
    int n; cin >> n;

    string pre;
    string suff;

    for (int i = 0; i < 2*n-2; i++) {
        string part; cin >> part;
        if (part.length() == n-1) {
            if (!pre.length())
                pre = part;
            else
                suff = part;
        }
    }

    int i = 1;
    for (; i < n-1; i++)
        if (pre[i] != suff[i-1])
            break;
    
    if (i != n-1) swap(pre, suff);
    string word = pre + suff[n-1-1];

    int c;
    for (c = 0; c < n/2; c++)
        if (word[c] != word[n-1-c])
            break;

    if (c == n/2)
        cout << "YES\n";
    else
        cout << "NO\n";
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}