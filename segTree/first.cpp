
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int l, r, m, val;
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void set(int i, int nVal) {
        if (l == r) return void(val = nVal);
        if (i <= m) z->set(i, nVal);
        else y->set(i, nVal);
        val = max(z->val, y->val);
    }

    int query(int x) {
        if (l == r) return l;
        if (z->val >= x) return z->query(x);
        else return y->query(x);
    }
};

int main() {
    int N, M; cin >> N >> M;
    Node* root = new Node(0, N - 1);
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        root->set(i, d);
    }

    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int i, v; cin >> i >> v;
            root->set(i, v);
        } else if (t == 2) {
            int x; cin >> x;
            if (root->val >= x) cout << root->query(x) << '\n';
            else cout << -1 << '\n';
        }
    }
}