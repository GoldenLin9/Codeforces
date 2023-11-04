#include <bits/stdc++.h>
using namespace std;


struct Node {
    int l, r, m, sum{};
    Node *z, *y;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }

    void set(int i) {
        if (l == r) return void(sum^= 1);
        if (i <= m) z->set(i);
        else y->set(i);
        sum = y->sum + z->sum;
    }

    int query(int lo, int hi) {
        if (lo <= l and r <= hi) return sum;
        if (hi < l or lo > r) return 0;
        return z->query(lo, hi) + y->query(lo, hi);
    }
};

int main() {
    int N; cin >> N;
    vector<int> idx(N+1, -1);
    vector<int> ans(N+1, -1);

    Node* root = new Node(0, 2*N-1);
    for (int i = 0; i < 2*N; i++) {
        int d; cin >> d;
        if (idx[d] == -1) idx[d] = i;
        else {
            ans[d] = root->query(idx[d], i);
            root->set(idx[d]);
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
}