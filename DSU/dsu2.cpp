#include <bits/stdc++.h>
using namespace std;
 
int N, M;
struct DSU {
    vector<int> s;
    vector<int> da;
    vector<int> xiao;
    DSU(int n): s(n, -1), da(n), xiao(n) {
        iota(da.begin(), da.end(), 0);
        iota(xiao.begin(), xiao.end(), 0);
    };
 
    int find(int x) { return s[x] < 0 ? x: s[x] = find(s[x]);}
    int join(int u, int v) {
        int a{u}, b{v};
        if ((u = find(u)) == (v = find(v))) return 0;
        if (s[u] > s[v]) swap(u, v);
        da[u] = max(da[u], da[v]);
        xiao[u] = min(xiao[u], xiao[v]);
        return s[u]+= s[v], s[v] = u, 1;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    N++;
    DSU dsu = DSU(N);
 
    while (M--) {
        string t; cin >> t;
        if (t == "union") {
            int u, v; cin >> u >> v;
            dsu.join(u, v);
        } else {
            int x; cin >> x;
            int leader = dsu.find(x);
            cout << dsu.xiao[leader] << ' ' << dsu.da[leader] << ' ' << -dsu.s[leader] << '\n';
        }
    }
}