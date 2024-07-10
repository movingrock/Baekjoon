#include <iostream>
#define MODULER 1000000000
using namespace std;

long long dp[101][10];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % MODULER;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % MODULER;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % MODULER;
		}
	}

	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += dp[n][i];
	}

	cout << answer % MODULER;

	return 0;
}