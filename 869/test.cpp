#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int n,q; cin >> n >> q;
    vi a(n);
    for(int& i : a) cin >> i;
    vi p(n-1);
    for(int i=1;i<n-1;++i) {
        int downhill = a[i-1]>=a[i] and a[i]>=a[i+1];
        p[i] = p[i-1] + downhill;
    }

    for (int i: p)
        cout << i << ' ';

}