#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int L; cin >> L;
        vector<pair<int, int>> lamps(L);
        for (int l = 0; l < L; l++) cin >> lamps[l].first >> lamps[l].second;
        sort(lamps.begin(), lamps.end(), [](auto a, auto b) {
            if (a.first < b.first) return true;
            else if (b.first < a.first) return false;
            else {
                if (a.second > b.second) return true;
                return false;
            }
        });

        int on{}, t{};
        long long pts{};
        priority_queue<int> pq;
        for (auto lamp: lamps) {
            if (lamp.first <= on) continue;
            on++;
            pts+= lamp.second;
            pq.push(-(t + lamp.first));

            while (!pq.empty()) {
                if (t >= -pq.top()) {
                    pq.pop();
                    on--;
                } else break;
            }

            t++;
        }

        cout << pts << '\n';
    }
    
}