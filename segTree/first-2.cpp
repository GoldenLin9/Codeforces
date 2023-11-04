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

    void set(int i, int d) {
        if (l == r) return void(val = d);
        if (i <= m) z->set(i, d);
        else y->set(i, d);
        val = max(z->val, y->val);
    }

    int query(int x, int j) {
        if (l == r and val < x) return -1;
        if (l == r) return l;

        int test{-1};
        if (j <= z->r and z->val >= x) test = z->query(x, j);

        if (test == -1) return y->query(x, j);
        else return test;
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
        int t, n1, n2; cin >> t >> n1 >> n2;
        if (t == 1) root->set(n1, n2);
        else cout << root->query(n1, n2) << '\n';
    }
}