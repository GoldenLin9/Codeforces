
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INF = 1e10;

ll oxygenNeeded, nitrogenNeeded;
ll n;

vector<vector<vector<ll>>> dp;
vector<ll> oxygen;
vector<ll> nitrogen;
vector<ll> weight;

ll solve(ll i, ll ox, ll ni) {
    if (i == n && ox >= oxygenNeeded && ni >= nitrogenNeeded) return 0;
    if (i == n) return INF;

    int oxInd = min(oxygenNeeded, ox);
    int niInd = min(nitrogenNeeded, ni);

    if (dp[i][oxInd][niInd] != -1) return dp[i][oxInd][niInd];
    
    ll takeCylinder = weight[i] + solve(i + 1, ox + oxygen[i], ni + nitrogen[i]);
    ll leaveCylinder = solve(i + 1, ox, ni);

    return dp[i][oxInd][niInd] = min(takeCylinder, leaveCylinder);
}

int main() {
    cin >> oxygenNeeded >> nitrogenNeeded;
    cin >> n;

    dp = vector<vector<vector<ll>>>(n, vector<vector<ll>>(oxygenNeeded + 1, vector<ll>(nitrogenNeeded + 1, -1)));
    oxygen = vector<ll>(n);
    nitrogen = vector<ll>(n);
    weight = vector<ll>(n);

    for (int i = 0; i < n; i++)
        cin >> oxygen[i] >> nitrogen[i] >> weight[i];
    
    cout << solve(0, 0, 0) << endl;
}