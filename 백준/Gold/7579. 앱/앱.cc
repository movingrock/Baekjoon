#include <iostream>

#define MAXN 101

using namespace std;

int arr[MAXN];
int c[MAXN];
int dp[MAXN][10001]; // dp[i][j] i번째 앱까지 포함해서 j 비용(c) 이하인 경우 중 최대 메모리 크기
int sum = 0; // 비용의 합
int n, m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum += c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - c[i] >= 0) {
				// i번째 앱을 포함하기 전까지의 최대값 + i번째 앱 비용
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + arr[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}


	return 0;
}