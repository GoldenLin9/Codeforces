#include <bits/stdc++.h>
using namespace std;


struct Node {
    int l, r, m, val{};
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void set(int lo, int hi, int nVal) {
        if (lo <= l and r <= hi) return void(val = max(val, nVal));
        if (lo > r or hi < l) return;
        z->set(lo, hi, nVal), y->set(lo, hi, nVal);
    }

    int get(int i) {
        if (l == r) return val;
        if (i <= m) return max(val, z->get(i));
        return max(val, y->get(i));
    }
};

int main() {
    int N, M; cin >> N >> M;
    Node* root = new Node(0, N - 1);

    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, v; cin >> l >> r >> v;
            root->set(l, r - 1, v);
        } else {
            int i; cin >> i;
            cout << root->get(i) << '\n';
        }
    }
}