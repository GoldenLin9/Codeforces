#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, m;
    long long o{}, e{};
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void set(int i, int nVal) {
        if (l == r) return void((o = -nVal, e = nVal));
        if (i <= m) z->set(i, nVal);
        else y->set(i, nVal);
        e = z->e;
        o = z->o;
        if (r - l == 1 or ((z->r - z->l) + 1) % 2 == 1) {
            e+= y->o;
            o+= y->e;
        } else {
            e+= y->e;
            o+= y->o;
        }
    }

    long long query(int lo, int hi) {
        if (lo <= l and r <= hi) return ((l - lo) % 2) ? o: e;
        if (lo > r or hi < l) return 0;
        return z->query(lo, hi) + y->query(lo, hi);
    }
};

int main() {
    int N; cin >> N;
    Node* root = new Node(0, N - 1);
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        root->set(i, d);
    }

    int M; cin >> M;
    while (M--) {
        int t; cin >> t;
        if (t) {
            int l, r; cin >> l >> r;
            cout << root->query(l-1, r-1) << '\n';
        } else {
            int i, d; cin >> i >> d;
            root->set(i-1, d);
        }
    }
}