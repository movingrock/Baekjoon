#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		int left = 0;
		int right = n - 1;
		bool find = false;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (target == v[mid]) { find = true; break; }

			if (target < v[mid]) right = mid - 1;
			else if (target > v[mid]) left = mid + 1;
		}

		cout << (find ? 1 : 0) << " ";

	}

	return 0;
}