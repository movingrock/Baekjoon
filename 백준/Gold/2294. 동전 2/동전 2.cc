#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>

#define INF 987654321

using namespace std;

int arr[101];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= k; i++) {
		dp[i] = INF;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	for (int i = 1; i <= k; i++) { // 현재 구하려는 합
		for (int j = 0; j < n; j++) { // n개의 동전
			if (i - arr[j] < 1) continue;

			dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}
	}

	if (dp[k] == INF) cout << -1;
	else cout << dp[k];

	return 0;
}