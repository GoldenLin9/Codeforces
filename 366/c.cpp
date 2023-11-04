#include <bits/stdc++.h>
using namespace std;


vector<long long> bit;
int N, Q;

long long sum(int i) {
    long long tot{};
    for (; i > 0; i-= i & -i)
        tot+= bit[i];
    return tot;
}

void upd(int app, long long val) {
    for (; app <= N; app+= app & -app)
        bit[app]+= val;
}

int main() {
    cin >> N >> Q;
    bit = vector<long long>(N+1, 0);
    int noti{};
    int read{};
    int t{};
    
    while (Q--) {
        int T, X; cin >> T >> X;

        if (T == 1) {
            upd(X, 1);
            noti++;
            cout << sum(N) - max(0, t-read) << '\n';

        } else if (T == 2) {
            long long notif = sum(X) - sum(X-1);
            upd(X, -notif);
            
            read+= notif;
            cout << sum(N) - max(0, (t-read)) << '\n';

        } else if (T == 3) {
            t+= X;
            cout << sum(N) - max(0, (t-read)) << '\n';
        }
    }
}
/*
P_Nyagolov
*/