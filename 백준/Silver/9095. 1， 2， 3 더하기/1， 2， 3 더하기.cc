#include <iostream>
#include <vector>

using namespace std;

int dp[11]; // 1~10

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}