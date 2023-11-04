#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> s;
    DSU(int n): s(n, -1) {}
    int par(int u) { return (s[u] < 0) ? u: s[u] = par(s[u]);}
    int join(int u, int v) {
        int pu = u = par(u);
        int pv = v = par(v);
        if (pu == pv) return 0;
        
        if (s[u] > s[v]) swap(u, v);
        return s[u]+= s[v], s[v] = u, 1;
    }
};

int main() {
    int M, N; cin >> M >> N;
    while(1) {
        if (M + N == 0) break;
        DSU dsu(M);
        vector<vector<int>> edges(N, vector<int>(3));
        int cost{};
        for (int i = 0; i < N; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
            cost+= edges[i][2];
        }

        sort(begin(edges), end(edges), [](vector<int> a, vector<int> b) {
            return a[2] < b[2];
        });

        for (vector<int> e: edges) {
            if (dsu.join(e[0], e[1])) cost-= e[2];
        }
        cout << cost << '\n';
        cin >> M >> N;
    }
}