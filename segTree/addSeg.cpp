#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, m;
    long long sum{};
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void set(int i, long long val) {
        if (l == r) return void(sum+= val);
        if (i <= m) z->set(i, val);
        else y->set(i, val);
        sum = z->sum + y->sum;
    }

    long long query(int hi) {
        if (l == r) return (hi == l) ? sum: 0;
        if (z->r <= hi) return z->sum + y->query(hi);
        else return z->query(hi);
    }
};

int main() {
    int N, M; cin >> N >> M;
    Node* root = new Node(0, N);

    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            long long v; cin >> v;
            root->set(l, v);
            root->set(r, -v);
        } else if (t == 2) {
            int i; cin >> i;
            cout << root->query(i) << '\n';
        }
    }
}