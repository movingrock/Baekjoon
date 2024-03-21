#include <iostream>
#include <vector>
using namespace std;

vector<int> v[501];
int dp[501][501];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cnt; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
		cnt++;
	}

	dp[0][0] = v[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + v[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + v[i][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + v[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[n - 1][i]);
	}

	cout << ans;

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < i + 1; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	return 0;
}