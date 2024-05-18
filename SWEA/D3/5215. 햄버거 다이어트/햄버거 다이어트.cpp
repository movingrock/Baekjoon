#include<iostream>

using namespace std;

int dp[21][10001] = { 0, }; // 0번부터 i 번째 물건까지 / 배낭 최대 무게

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, l;
		cin >> n >> l;
		int score[21];
		int cal[21];
		for (int i = 1; i <= n; i++) {
			cin >> score[i] >> cal[i];
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= l; j++) {
				if (cal[i] > j) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cal[i]] + score[i]);
			}
		}

		cout << "#" << test_case << " " << dp[n][l] << endl;
	}
	return 0;
}