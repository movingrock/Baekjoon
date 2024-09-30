#include <iostream>
#include <vector>

#define MAX 1500001
#define INF INT_MAX

using namespace std;

int n;
pair<int, int> arr[MAX];
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, p; cin >> t >> p;
		arr[i] = { t, p };
	}

	int answer = 0;
	for (int i = 1; i <= n+1; i++) {
		answer = max(answer, dp[i]);
		int endDay = i + arr[i].first;
		if (endDay > n + 1) continue;
		
		dp[endDay] = max(dp[endDay], answer + arr[i].second);
	}

	cout << answer;

	return 0;
}