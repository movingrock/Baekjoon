#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	int arr[10];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] <= k) {
			cnt += k / arr[i];
			k = k % arr[i];
		}
	}

	cout << cnt;

	return 0;
}