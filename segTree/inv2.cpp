#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r, m;
    long long val{1}, sum{1};
    Node *z, *y;
    
    Node(int l, int r): l(l), r(r), m(l + r >> 1) {
        if (l == r) return;
        z = new Node(l, m);
        y = new Node(m + 1, r);
        sum = z->sum + y->sum;
    }

    int mark(int a4) {
        if (l == r) return sum = 0, l + 1;
        int ret;
        if (y->sum > a4) ret = y->mark(a4);
        else ret = z->mark(a4 - y->sum);
        sum = z->sum + y->sum;
        return ret;
    }
};

int main() {
    int N; cin >> N;
    vector<int> count(N);
    for (int& n: count) cin >> n;

    Node* root = new Node(0, N - 1);
    for (int i = N - 1; i >= 0; i--) count[i] = root->mark(count[i]);
    for (int i = 0; i < N; i++) cout << count[i] << " \n"[i == N-1];
}