#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, m;
    long long pref{(long long)(-1e18)}, suff{(long long)(-1e18)}, sum{(long long)(-1e18)}, seg{(long long)(-1e18)};
    Node *left, *right;

    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        left = new Node(l, m);
        right = new Node(m+1, r);
    }

    long long set(int i, long long nVal) {
        if (l == r) return pref = suff = sum = seg = nVal;
        if (i <= m) left->set(i, nVal);
        else right->set(i, nVal);
        sum = left->sum + right->sum;
        pref = max({left->sum + right->pref, left->pref});
        suff = max({right->suff, right->sum + left->suff});
        seg = max({right->seg, left->seg, left->suff + right->pref});
        return max(0LL, seg);
    }
};

int main() {
    int N, M; cin >> N >> M;
    Node* root = new Node(0, N-1);
    for (int i = 0; i < N; i++) {
        long long d; cin >> d;
        root->set(i, d);
    }

    cout << max(0LL, root->seg) << '\n';
    while (M--) {
        int i; long long v; cin >> i >> v;
        cout << max(0LL, root->set(i, v)) << '\n';
    }
}