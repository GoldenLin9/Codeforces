#include <bits/stdc++.h>
using namespace std;


int N, K;
vector<int> nums;


int main() {
    cin >> N >> K;
    nums = vector<int>(N);
	for (int &n: nums) cin >> n;

	for (int k = 0; k < K; k++) {
		int num; cin >> num;

		int lo{};
		int hi{N-1};
		int ans{-1};

		while (lo <= hi) {
			
			int m = lo + (hi - lo + 1)/2;

			if (nums[m] == num) {
				ans = m;
				break;
			}

			if (nums[m] > num) hi = m - 1;
			else lo = m + 1;
		}

		if (ans == -1) cout << "NO\n";
		else cout << "YES\n";
	}
}