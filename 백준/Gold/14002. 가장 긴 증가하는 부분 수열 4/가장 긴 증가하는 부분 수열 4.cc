#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];
vector<int> answer[1001];
vector<int> answer2;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		answer[i].push_back(arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				answer[i].clear();
				answer[i] = answer[j];
				answer[i].push_back(arr[i]);
				dp[i] = dp[j] + 1;
			}
		}
		if (answer2.size() < answer[i].size()) answer2 = answer[i];
	}

	cout << answer2.size() << endl;
	for (int i = 0; i < answer2.size(); i++) {
		cout << answer2[i] << " ";
	}

	return 0;
}