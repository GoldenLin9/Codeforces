#include "bits/stdc++.h"
 
using namespace std;
 
#define ll long long
 
int main() {
  
  int t; cin >> t;
  while (t--) {
 
    int n; cin >> n;
 
    int a = 0;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      a ^= x;
      cout << a << '\n';
    }

    cout << "res: " << a << '\n';
 
    if (a == 0 || (n % 2)) {
      cout << a << "\n";
    }
    else {
      cout << "-1\n";
    }
 
  }
  
}