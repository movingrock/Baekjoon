#include <iostream>
#include <climits>

#define MAX 1001
#define INF 1000001;

using namespace std;


int arr[MAX][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	int answer = INF;
	// 1번집과 n번째 집이 다를때의 최소비용 구하기
	for (int i = 0; i <= 2; i++) {
		int dp[MAX][3];
		for (int j = 0; j <= 2; j++) {
			if (i == j) dp[1][i] = arr[1][i];
			else dp[1][j] = INF;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + arr[j][2];
		}
		for (int j = 0; j <= 2; j++) {
			if (i == j) continue;
			answer = min(answer, dp[n][j]);
		}
	}

	cout << answer;

	return 0;
}