#include <bits/stdc++.h>
long long m{int(1e9) + 7};
long long expo(long long b, long long k) {return !k ? 1: 1 * (k % 2 ? b * expo(b*b % m, k/2): expo(b*b % m, k/2)) % m;};

int main() {
    int N, D, K, S; std::cin >> N >> D >> K >> S;
    long long r = std::min(N, 2*D + 1);
    if (r == 1) std::cout << K << '\n';
    else std::cout << (expo(r, K) - 1) * expo(r-1, m - 2) % m << '\n';
}