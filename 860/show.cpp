#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s; cin >> s;

    vector<int> a;
    vector<int> b;

    a = vector<int>(s);
    b = vector<int>(s);

    int am{}, bm{};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < s; j++) {
            if (i == 0) {

                int an; cin >> an;
                am = max(am, an);
                a[j] = an;

            } else {
                int bn; cin >> bn;
                bm = max(bm, bn);
                b[j] = bn;
            }
        }
    }

    int al{a.back()}, bl{b.back()};

    for (int i = s-1; i >= 0; i--) {
        int an{a[i]}, bn{b[i]};
        
        if (al != am) {
            if (bn <= am && ((an > am && i != s-1) || (i== s-1 && ))
                swap(a[i], b[i]);

        }
    }


    for (int a1: a)
        cout << a1 << ' ';
    cout << endl;
    
    for (int b1: b)
        cout << b1 << ' ';


}


int main() {
    int t; cin >> t;
    while (t--) solve();
}