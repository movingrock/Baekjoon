#include <iostream>

using namespace std;

int dp[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	if (dp[n] % 2 == 1) cout << "SK";
	else cout << "CY";

	return 0;
}