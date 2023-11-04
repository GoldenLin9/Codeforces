#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N; cin >> N;

    // vector<int> ac(4*int(1e5) + 1, 0);
    map<int, int> ac;
    int best{};
    for (int k = 0; k < 2; k++) {
        int curr{}, last{};
        for (int i = 0; i < N; i++) {
            int d; cin >> d;
            if (!k) {
                if (!i) {
                    curr++;
                    last = d;
                    ac[d] = 1;
                } else {
                    if (d == last) curr++;
                    else {
                        if (ac.find(d) != ac.end())
                            ac[d] = max(ac[d], curr);
                        else ac[d] = curr;
                        curr = 1;
                        last = d;
                    }
                }
            } else {
                if (!i) {
                    curr++;
                    last = d;
                    if (ac.find(d) != ac.end())
                        best = max(best, ac[d]+1);
                    else best = max(best, curr);
                } else {
                    if (d == last) curr++;
                    else {
                        if (ac.find(d) != ac.end())
                            best = max(best, ac[d]+curr);
                        else best = max(best, curr);
                        curr = 1;
                        last = d;
                    }
                }
            }
        }

        if (!k) {
            if (ac.find(last) != ac.end())
                ac[last] = max(ac[last], curr);
            else ac[last] = curr;
        }
        else {
            if (ac.find(last) != ac.end())
                best = max(best, ac[last] + curr);
            else best = max(best, curr);

        }
    }


    // int best{};
    // for (int i = 0; i < ac.size(); i++) best = max(best, ac[i] + bc[i]);
    cout << best << '\n';

}


int main() {
    int t; cin >> t;
    while (t--) solve();
}