#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> pts;
    vector<int> s;
    DSU(int n): pts(n, 0), s(n, -1) {};

    int find(int x) {
        if (s[x] < 0) return x;
        else {
            if (s[s[x]] > 0) pts[x]+= pts[s[x]];
            s[x] = find(s[x]);
            return s[x];
        }
    }

    int join(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return false;
        if (s[v] < s[u]) swap(v, u);
        s[u]+= s[v];
        s[v] = u;
        pts[v]-= pts[u];
        return true;
    }

    void add(int x, int v) {
        int lead = find(x);
        pts[lead]+= v;
    }
};


int main() {
    int N, M; cin >> N >> M;
    N++;
    DSU dsu(N+1);
    
    while (M--) {
        string t; cin >> t;
        if (t == "add") {
            int x, v; cin >> x >> v;
            dsu.add(x, v);
        } else if (t == "get") {
            int x; cin >> x;
            dsu.find(x);

            if (dsu.s[x] < 0) cout << dsu.pts[x] << '\n';
            else cout << dsu.pts[x] + dsu.pts[dsu.s[x]] << '\n';
        } else {
            int x, y; cin >> x >> y;
            dsu.join(x, y);
        }
    }
}