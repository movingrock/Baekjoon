#include <iostream>

using namespace std;

long long arr[1000001];
long long sum[1000001];
long long remain[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
		remain[sum[i] % m]++;
	}

	remain[0]++;
	long long answer = 0;
	for (int i = 0; i <= m; i++) {
		answer += (remain[i] * (remain[i] - 1)) / 2;
	}

	cout << answer;

	return 0;
}