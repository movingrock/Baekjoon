#include <iostream>

using namespace std;

int dp[31][31];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[0][0] = 1;
	for (int i = 0; i < 30; i++) {
		dp[0][i] = 1;
		dp[i][i] = 1;
	}

	for (int i = 1; i < 30; i++) {
		for (int j = i + 1; j < 30; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << dp[n][m] << "\n";
	}

	return 0;
}