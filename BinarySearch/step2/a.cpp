#include <bits/stdc++.h>
using namespace std;

bool isValid(long long w, long long h, long long n, long long x) {
    
    return (x/h * x/w >= n);
}

int main() {

    long long l = 1;
    long long r = 1;

    long long w, h, n; cin >> w >> h >> n;
    while (not isValid(w, h, n, r)) {
        r<<= 2;
    }



    while (l + 1 < r) {
        
        long long m = l + (r - l)/2;

        if (isValid(w, h, n, m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << '\n';

}