#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int m;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;

	sort(v.begin(), v.end());

	int left = 0;
	int right = v[n - 1];
	int a_sum = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] < mid) sum += v[i];
			else sum += mid;
		}

		if (sum > m) right = mid - 1;
		else if (sum <= m) left = mid + 1;
	}

	cout << left - 1;


	return 0;
}