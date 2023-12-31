#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int arr[101];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max_sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum <= m) max_sum = max(max_sum, sum);

			}
		}
	}
	cout << max_sum;

	return 0;
}