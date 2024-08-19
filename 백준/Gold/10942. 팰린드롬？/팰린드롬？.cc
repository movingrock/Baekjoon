#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[2001];
int dp[2001][2001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1) dp[i][j] = 1;
		}
	}

	cin >> m;
	while(m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s-1][e-1] << "\n";
	}

	return 0;
}