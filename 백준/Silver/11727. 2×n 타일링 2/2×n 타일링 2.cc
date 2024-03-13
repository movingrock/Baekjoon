#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	long long dp[1001];
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	dp[4] = 11;
	for (int i = 4; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}