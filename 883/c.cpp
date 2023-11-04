#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N, Q, T; cin >> N >> Q >> T;
    vector<vector<int>> scoreboard;

    for (int n = 0; n < N; n++) {
        vector<int> nums(Q);
        for (int&n: nums) cin >> n;
        sort(nums.begin(), nums.end());

        int past{}, pp{}, AC{};
        for (int n: nums) {
            if (past + n <= T) {
                AC++;
                past+= n;
                pp+= past;
            } else break;
        }

        vector<int> data = {AC, pp, n+1};
        scoreboard.push_back(data);
    }

    sort(scoreboard.begin(), scoreboard.end(), [](vector<int> a, vector<int> b) {
        // cout << "sdfsdfsd" << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
        // if (a[0] < b[0]) return false;
        // else if (a[1] < b[1]) return true;
        // else if (a[2] < b[2]) return true;
        // else return false;

        if (a[0] == b[0] and a[1] == b[1]) {
            if (a[2] < b[2]) return true;
            else return false;
        }

        if (a[0] == b[0]) {
            if (a[1] < b[1]) return true;
            else return false;
        }

        if (a[0] < b[0]) return false;
        else return true;


    });

    for (int s = 0; s < scoreboard.size(); s++) {
        // cout << scoreboard[s][0] << ' ' << scoreboard[s][1] << ' ' << scoreboard[s][2] << '\n';
        if (scoreboard[s][2] == 1) cout << s + 1 << '\n'; 
    }
}


int main() {
    int t; cin >> t;
    while (t--) solve();
}