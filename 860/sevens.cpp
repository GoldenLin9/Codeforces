#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> occ(10, 0);

    string s; cin >> s;

    int duo{};
    int t{s.length()};

    for (int c = 0; c < t; c++)
        duo = max(duo, ++occ[s[c] - '0']);

    if (duo == t)
        cout << -1 << '\n';
    else if (duo <= t - duo + 1)
        cout << t << '\n';
    else {
        int guan = (duo - (t-duo)) - 1;
        int twos{guan/2};
        int ones = guan & 1;

        int ops = twos*4 + ones*3 + (t-duo + 1) + (t-duo);
        // printf("twos: %d ones: %d guan: %d\n", twos, ones, guan);
        cout << ops << '\n';
    }

}

int main() {
    int t; cin >> t;

    while (t--) solve();
}