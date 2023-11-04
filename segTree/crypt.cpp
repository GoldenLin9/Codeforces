#include <bits/stdc++.h>
using namespace std;
 
int R;
int N, q;
 
struct M {
    int m[4] = {1, 0, 0, 1};
 
    M operator * (const M& other) {
        M res;
        res.m[0] = (other.m[0]*m[0] + other.m[2]*m[1]) % R;
        res.m[2] = (other.m[0]*m[2] + other.m[2]*m[3]) % R;
        res.m[1] = (other.m[1]*m[0] + other.m[3]*m[1]) % R;
        res.m[3] = (other.m[3]*m[3] + other.m[1]*m[2]) % R;
 
        return res;
    }
};
 
 
struct Node {
    int l, r, m;
    M mat;
    Node *z, *y;
 
    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
    }
 
    void set(int i, int a, int b, int c, int d) {
        if (l == r) {
            mat.m[0] = a;
            mat.m[1] = b;
            mat.m[2] = c;
            mat.m[3] = d;
            return;
        }
        if (i <= m) z->set(i, a, b, c, d);
        else y->set(i, a, b, c, d);
        mat = z->mat * y->mat;
    }
 
    M query(int lo, int hi) {
        if (lo <= l and r <= hi) return mat;
        if (lo > r or hi < l) return M();
        return z->query(lo, hi) * y->query(lo, hi);
    }
};
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> N >> q;
    Node* root = new Node(0, N-1);
    for (int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        root->set(i, a, b, c, d);
    }
 
    while (q--) {
        int l, r; cin >> l >> r;
        M res = root->query(l - 1, r - 1);
 
    cout << res.m[0] << ' ' << res.m[1] << '\n';
    cout << res.m[2] << ' ' << res.m[3] << '\n';
        
        cout << '\n';
    }
}