#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> v1, pair<int, int> v2) {
	if (v1.second == v2.second) return v1.first < v2.first;
	return v1.second < v2.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	int time = v[0].second;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].first >= time) {
			time = v[i].second;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}