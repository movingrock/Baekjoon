#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<int> first;
	vector<int> second;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			first.push_back(a[i] + b[j]);
			second.push_back(c[i] + d[j]);
		}
	}

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	long long answer = 0;

	for (int i = 0; i < first.size(); i++) {
		int x = lower_bound(second.begin(), second.end(), -first[i]) - second.begin();
		int y = upper_bound(second.begin(), second.end(), -first[i]) - second.begin();

		answer += y - x;
	}

	cout << answer;

	return 0;
}