#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        vector<int> a, b;
        int N; cin >> N;
        for (int& n: a) cin >> n;
        for (int& n: b) cin >> n;

        int total{};
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (a[i]*a[j] == b[i] + b[j])
                    total++;
                    
        cout << total << '\n';
    }
}