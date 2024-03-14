#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long max_tree = INT_MIN;
long long n, m;
vector<long long> v;
long long ans = 0;

long long binary_search() {
	long long low = 0;
	long long high = max_tree;

	while (low <= high) {
		long long sum = 0;
		long long mid = (low + high) / 2;

		for (int j = 0; j < n; j++) {
			if (v[j] > mid) sum += (v[j] - mid);
		}

		if (sum >= m) {
			low = mid + 1;
			ans = mid;
		}
		else if (sum < m) {
			high = mid - 1;
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long tree;
		cin >> tree;
		v.push_back(tree);
		max_tree = max(max_tree, tree);
	}

	sort(v.begin(), v.end());

	binary_search();

	cout << ans;

	return 0;
}