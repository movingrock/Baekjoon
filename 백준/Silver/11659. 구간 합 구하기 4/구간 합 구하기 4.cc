#include <iostream>

using namespace std;

int arr[100001];
int sum[100001] = { 0, };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + arr[i];
	}

	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << "\n";
	}

	return 0;
}