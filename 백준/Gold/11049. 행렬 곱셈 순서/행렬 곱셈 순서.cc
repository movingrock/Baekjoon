#include <iostream>
#include <climits>

#define INF INT_MAX;

using namespace std;

int dp[501][501];

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	int r[501];
	int c[501];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> c[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + r[j] * c[k] * c[i + j]);
			}
		}
	}

	cout << dp[1][n];

	return 0;
}