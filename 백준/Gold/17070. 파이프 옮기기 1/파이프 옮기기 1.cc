#include <iostream>

using namespace std;

int grid[17][17];
int dp[17][17][3]; // 0가로 1 세로 2대각선

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	} 

	dp[1][2][0] = 1;
	for (int j = 3; j <= n; j++) {
		if (grid[1][j] != 1) dp[1][j][0] = dp[1][j - 1][0];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 3; j <= n; j++) {
			if (grid[i][j] != 1) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
				if (grid[i - 1][j] != 1 && grid[i][j - 1] != 1) {
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];

				}
			}
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

	return 0;
}