#include <iostream>
#include <climits>
using namespace std;

int arr[100001];
int sum[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sum[0] = 0;
	int answer = INT_MIN;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = k; i <= n; i++) {
		answer = max(answer, sum[i] - sum[i-k]);
	}

	cout << answer;

	return 0;
}