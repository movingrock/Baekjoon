#include <iostream>
#include <vector>

using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}


	int i = a.size();
	int j = b.size();

	vector<char> answer;

	while (i != 0 && j != 0) {
		if (dp[i][j] == dp[i - 1][j]) i--;
		else if (dp[i][j] == dp[i][j - 1]) j--;
		else {
			answer.push_back(a[i - 1]);
			i--;
			j--;
		}
	}

	cout << dp[a.size()][b.size()] << "\n";
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i];
	}

	return 0;
}