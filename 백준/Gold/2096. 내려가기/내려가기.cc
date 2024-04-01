#include <iostream>

using namespace std;

int max_dp[3] = { 0, };
int max_tmp[3];
int min_dp[3] = { 0, };
int min_tmp[3];
int num[3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 3; i++) {
		cin >> num[i];
		max_dp[i] = num[i];
		min_dp[i] = num[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> num[j];
			max_tmp[j] = max_dp[j];
			min_tmp[j] = min_dp[j];
		}
		max_dp[0] = max(max_tmp[0], max_tmp[1]) + num[0];
		min_dp[0] = min(min_tmp[0], min_tmp[1]) + num[0];

		max_dp[1] = max(max_tmp[0], max(max_tmp[1], max_tmp[2])) + num[1];
		min_dp[1] = min(min_tmp[0], min(min_tmp[1], min_tmp[2])) + num[1];
	
		max_dp[2] = max(max_tmp[2], max_tmp[1]) + num[2];
		min_dp[2] = min(min_tmp[2], min_tmp[1]) + num[2];
	}

	cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " " << min(min_dp[0], min(min_dp[1], min_dp[2]));

	return 0;
}