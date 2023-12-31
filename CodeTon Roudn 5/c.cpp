#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    std::vector<int> dp(n + 1), f(n, -1E9);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = std::max(dp[i], f[a[i]] + i + 1);
        f[a[i]] = std::max(f[a[i]], dp[i] - i);
    }
    
    for (auto n: dp) std::cout << n << ' ';
    std::cout << '\n';

    for (auto n: f) std::cout << n << ' ';
    std::cout << '\n';
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
