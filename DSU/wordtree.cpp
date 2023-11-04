#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<string> bijection;

struct int3
{
    int x, y, z;
    int3(){}
    int3(int x_, int y_, int z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
    bool operator < (const int3& other) const
    {
        return z < other.z;
    }
};

int cost(int u, int v) {
    int cost{};
    for (int i = 0; i < K; i++) cost+= abs(bijection[u][i] - bijection[v][i]);
    return cost;
}

struct DSU {
    vector<int> par;
    DSU(int n): par(n, -1) {};
    int find(int u) {return (par[u] < 0) ? u: par[u] = find(par[u]);}
    int join(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return 0;
        if (par[u] > par[v]) swap(u, v);
        return par[u]+= par[v], par[v] = u, 1;
    }
};

int main() {
    cin >> N >> K;
    DSU dsu(N);
    for (int i = 0; i < N; i++) {
        string w; cin >> w;
        bijection.push_back(w);
    }

    vector<int3> edges;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j) {
                int3 stuff(i, j, cost(i, j));
                edges.push_back({i, j, cost(i, j)});
            }
    sort(begin(edges), end(edges));
    

    int high{};
    int connections{};
    for (int3 e: edges) {
        if (dsu.join(e.x, e.y)) {
            connections+= 1;
            high = max(high, e.z);
        }
        if (connections == N - 1) break;
    }
    cout << high << '\n';
}