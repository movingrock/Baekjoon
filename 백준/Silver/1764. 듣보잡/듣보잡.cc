#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	map<string, bool> map;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		map.insert(make_pair(str, true));
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (map[str]) {
			cnt++;
			v.push_back(str);
		}
	}
	sort(v.begin(), v.end());

	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}