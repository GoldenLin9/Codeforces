#include <bits/stdc++.h>
using namespace std;


struct Node {
    int l, r, m;
    long long zong{};
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void add(int lo, int hi, long long nVal) {
        if (lo <= l and r <= hi) return void(zong+= nVal);
        if (hi < l or lo > r) return;
        else z->add(lo, hi, nVal), y->add(lo, hi, nVal);
    }

    long long get(int i) {
        if (l == r) return zong;
        if (i <= m) return zong + z->get(i);
        return zong + y->get(i);
    }
};


int main() {
    int N, M; cin >> N >> M;
    Node* root = new Node(0, N - 1);

    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r;
            long long nVal;
            cin >> l >> r >> nVal;
            root->add(l, r - 1, nVal);
        } else {
            int i; cin >> i;
            cout << root->get(i) << '\n';
        }
    }
}