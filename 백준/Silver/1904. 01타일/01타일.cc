#include <iostream>
#define MODULER 15746
using namespace std;

long long dp[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % MODULER;
	}

	cout << dp[n];

	return 0;
}