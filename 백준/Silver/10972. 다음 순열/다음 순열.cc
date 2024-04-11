#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	if (next_permutation(v.begin(), v.end())) {
		for (auto i : v) cout << i << ' ';
	}
	else cout << -1;

	return 0;
}