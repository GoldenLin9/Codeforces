#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, m; cin >> n >> m;

    vector<int> N(n);
    vector<int> M(m);

    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> M[i];
    }

    int pn = -1;

    for (int num: M) {

        while (pn < (int)N.size() && N[pn+1] < num) {
            pn++;
        }
        cout << ((pn == (int) N.size()) ? N.size(): pn + 1) << ' ';
    }
}