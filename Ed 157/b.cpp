#include <bits/stdc++.h>
using namespace std;


void solve() {
    int pairs; cin >> pairs;
    vector<pair<int, int>> coords(pairs);

    vector<int> points(pairs*2);
    for (int& n: points) cin >> n;

    sort(points.begin(), points.end());

    for (int i = 0; i < 2*pairs; i++) {
        if (i < pairs) coords[i].first = points[i];
        else coords[i - pairs].second = points[i];
    }

    int score{};
    for (int i = 0; i < pairs - 1; i++) score+= abs(coords[i + 1].first - coords[i].first) + abs(coords[i + 1].second - coords[i].second);

    cout << score << '\n';
    for (auto p: coords) cout << p.first << ' ' << p.second << '\n';
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}