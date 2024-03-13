#include <iostream>
#include <map>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		map<string, int> map;

		for (int i = 0; i < n; i++) {
			string name, type;
			cin >> name >> type;
			if (map.find(type) == map.end()) map.insert({ type, 1 });
			else map[type]++;
		}

		int ans = 1;

		for (auto iter = map.begin(); iter != map.end(); iter++) {
			ans *= (iter->second + 1);
		}

		cout << ans - 1 << "\n";

	}


	return 0;
}