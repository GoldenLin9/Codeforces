#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n): p(n, -1) {};
    int find(int u) {
        if (p[u] < 0) return u;
        else {
            p[u] = find(p[u]);
            return p[u];
        }
    }

    int join(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return 0;
        if (p[u] > p[v]) swap(u, v);
        p[u]+= p[v];
        p[v] = u;
        return 1;
    }
};

int main() {
    int n, m; cin >> n >> m;
    DSU d = DSU(n+1);
    while (m--) {
        string t; cin >> t;
        if (t == "union") {
            int u, v; cin >> u >> v;
            d.join(u, v);
        } else if (t == "get") {
            int u, v; cin >> u >> v;
            if (d.find(u) == d.find(v)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}