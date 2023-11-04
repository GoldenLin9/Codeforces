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
    void set(int i) {
        if (l == r) return void(val^=1);
        if (i <= m) z->set(i);
        else y->set(i);
        val = z->val + y->val;
    }
    int query(int k) {
        if (l == r) return l;
        if (k <= z->val) return z->query(k);
        else return y->query(k- z->val);
    }
};

int main() {
    int N, M; cin >> N >> M;
    Node* root = new Node(0, N-1);
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        if (d) root->set(i);
    }
    
    while (M--) {
        int t, n; cin >> t >> n;
        if (t == 1) root->set(n);
        else if (t == 2) cout << root->query(n+1) << '\n';
    }
}