#include <bits/stdc++.h>
using namespace std;


struct Node {
    int l, r, m, zong{}, val{};
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void set(int i) {
        if (l == r) return void(val = 1);
        if (i <= m) z->set(i);
        else y->set(i);
        val = z->val + y->val;
    }

    int query(int l) {
        if (l > r) return 0;
        if (y->l >= l) return y->val + z->query(l);
        else return y->query(l);
    }
};


int main() {
    int N; cin >> N;
    Node* root = new Node(0, N-1);
    for (int i = 0; i < N; i++) {
        int d; cin >> d;
        root->set(d-1);
        cout << root->query(d) << '\n';
    }
}