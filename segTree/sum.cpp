#include <bits/stdc++.h>
using namespace std;

int N, M;


struct Node {
    int l, r, m;
    long long val;
    Node *z, *y;
    Node(int l, int r): l(l), r(r), m(l+r >> 1) {
        if (l == r) return;
        this->z = new Node(l, m);
        this->y = new Node(m+1, r);
        this->val = z->val + y->val;
    }

    void set(int i, long long val) {
        if (this->r == this->l) {
            this->val = val;
            return;
        }
        if (i <= this->m) z->set(i, val);
        else y->set(i, val);
        this->val = z->val + y->val;
    }

    long long query(int lo, int hi) {
        if (hi < this->l or this->r < lo) return 0;
        else if (hi >= this->r and lo <= this->l) return this->val;
        else return z->query(lo, hi) + y->query(lo, hi);
    }
};

int main() {
    cin >> N >> M;
    Node* root = new Node(0, N-1);
    for (int i = 0; i < N; i++) {
        long long d; cin >> d;
        root->set(i, d);
    }

    while (M--) {
        long long t, n1, n2; cin >> t >> n1 >> n2;
        if (t == 1) root->set(n1, n2);
        else cout << root->query(n1, n2-1) << '\n';
    }
}