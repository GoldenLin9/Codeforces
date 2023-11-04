#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, m;
    pair<int, int> data = {0, 1e9};
    Node *z, *y;

    pair<int, int> merge(pair<int, int> z, pair<int, int> y) {
        if (y.second < z.second) return y;
        else if (z.second < y.second) return z;
        else return {y.first + z.first, z.second};
    }

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l != r) z = new Node(l, m), y = new Node(m+1, r);
    }

    void set(int i, int nVal) {
        if (l == r) return void(data = {1, nVal});
        if (i <= m) z->set(i, nVal);
        else y->set(i, nVal);
        data = merge(z->data, y->data);
    }

    pair<int, int> query(int lo, int hi) {
        if (lo <= l and r <= hi) return data;
        if (lo > r or hi < l) return {0, 1e9};
        return merge(z->query(lo, hi), y->query(lo, hi));
    }
};


int main() {
    int N, M; cin >> N >> M;
    Node* root = new Node(0, N-1);
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        root->set(i, d);
    }

    while (M--) {
        int t, f, s; cin >> t >> f >> s;
        if (t == 1) root->set(f, s);
        else {
            pair<int, int> res = root->query(f, s-1);
            cout << res.second << ' ' << res.first << '\n';
        }
    }
}