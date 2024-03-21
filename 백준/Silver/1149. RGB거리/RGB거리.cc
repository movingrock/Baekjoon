#include <iostream>
#include <climits>
using namespace std;

int dp[1001][3] = { 0, };

// 0 1 2
// R G B

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int ans = INT_MAX;

	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		dp[i][0] = min(dp[i - 1][1] + r, dp[i - 1][2] + r);
		dp[i][1] = min(dp[i - 1][0] + g, dp[i - 1][2] + g);
		dp[i][2] = min(dp[i - 1][0] + b, dp[i - 1][1] + b);

	}
	ans = min(ans, min(dp[n][0], min(dp[n][1], dp[n][2])));

	cout << ans;

	return 0;
}