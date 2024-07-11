#include <iostream>

using namespace std;

long long arr[10001];
long long sum[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long n, m;
	cin >> n >> m;

	long long answer = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (sum[j] - sum[i] == m) answer++;
		}
	}
	cout << answer;
	return 0;
}