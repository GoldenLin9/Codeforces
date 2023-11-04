#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define sz(x) (int)(x).size()
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;

        int n1 = s1.size(), n2 = s2.size();

        // vector<vector<int>> graph(n1 + n2 + 2);

        Dinic graph = Dinic(n1 + n2 + 2);

        for (int i = 0; i < n1; i++)
            for (int j = 0; j < n2; j++)
                if (abs(s1[i] - s2[j]) >= 3)
                    graph.addEdge(i, n1 + j, 1);
        
        int s = n1 + n2, t = s + 1;

        for (int i = 0; i < n1; i++)
            graph.addEdge(s, i, 1);
        
        for (int i = n1; i < n1 + n2; i++)
            graph.addEdge(i, t, 1);

        cout << graph.calc(s, t) << endl;
    }
}