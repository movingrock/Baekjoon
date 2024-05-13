#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> t(n+1);
	vector<int> p(n+1);
	int dp[16] = { 0, };
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		if(i + t[i] - 1 <= n) dp[i] = p[i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (j + t[j] - 1 >= i) continue; // 전날들의 일이 지금 날짜를 넘으면
			if (i + t[i] - 1 <= n) dp[i] = max(dp[i], dp[j] + p[i]); // 오늘 일이 n 일전에 안끝난다면
			else dp[i] = max(dp[i], dp[j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans;


	return 0;
}
