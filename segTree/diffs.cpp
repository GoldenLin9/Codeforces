#include <bits/stdc++.h>
using namespace std;


struct Node {
    int l, r, m;
    unsigned long long mask{};
    Node *z, *y;
    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void set(int i, int nVal) {
        if (l == r) return void(mask = 1ULL << nVal);
        if (i <= m) z->set(i, nVal);
        else y->set(i, nVal);
        mask = z->mask | y->mask;
    }

    unsigned long long query(int lo, int hi) {
        if (lo <= l and r <= hi) return mask;
        if (l > hi or r < lo) return 0ULL;
        return z->query(lo, hi) | y->query(lo, hi);
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
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            unsigned long long mask = root->query(x-1, y-1);
            int u{};
            for (int i = 0; i < 64; i++)
                if ((1ULL << i) & mask) u++;
            cout << u << '\n';
        } else {
            int x, y; cin >> x >> y;
            root->set(x-1, y);
        }
    }
}