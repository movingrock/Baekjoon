#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];
int dp2[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 기본은 다 1임
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	for (int i = n-1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n-1; j > i; j--) {
			if (arr[j] < arr[i]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i] + dp2[i] - 1);
	}

	cout << ans;

	return 0;
}