#include <bits/stdc++.h>
using namespace std;

void count(int n)

int T(int n) {
	cout << n << '\n';
	if (n == 1) return 1;
	return 2*T(n-2) + n;
}

int main() {
	cout << T(4);
}