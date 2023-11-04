#include <bits/stdc++.h>
using namespace std;


int belt(long long int x, long long int y, long long int n) {
    x = min(x, n-x+1);

    if (y >= x && y < x + (n-(2*max(0LL, x-1))))
        return min(x, n-x+1);
    else
        return min(n-y+1, y);
}




int main() {
    int t; cin >> t;
    while (t--) {
        long long int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
        cout << abs(belt(x1, y1, n) - belt(x2, y2, n)) << '\n';
    }
}