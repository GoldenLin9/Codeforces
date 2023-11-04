#include <bits/stdc++.h>
using namespace std;


struct Node {
    int l, r, m, val{int(1e9)};
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m+1, r);
    }

    void set(int i, int nVal) {
        if (l == r) {
            val = nVal;
            return;
        }
        if (i <= m) z->set(i, nVal);
        else y->set(i, nVal);
        val = min(y->val, z->val);
    }

    int query(int lo, int hi) {
        if (lo <= l and r <= hi) return val;
        else if (lo > r or hi < l) return 1e9;
        else return min(z->query(lo, hi), y->query(lo, hi));
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
        else cout << root->query(f, s-1) << '\n';
    }
}