#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[101];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k];

	return 0;
}