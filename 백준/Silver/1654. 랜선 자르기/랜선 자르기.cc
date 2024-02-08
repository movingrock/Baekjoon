#include <iostream>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int k, n;
	cin >> k >> n;
	int arr[10000];
	int longest = 0;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		longest = max(longest, arr[i]);
	}
	
	long long left = 1;
	long long right = longest;
	long long mid;
	long long ans = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += (arr[i] / mid);
		}

		if (sum >= n) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	
	cout << ans;

	return 0;
}