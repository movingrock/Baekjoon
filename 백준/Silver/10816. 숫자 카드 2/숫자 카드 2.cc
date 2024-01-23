#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	map<int, int> map;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		map[num]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (map.find(num) != map.end()) cout << map.find(num)->second << " ";
		else cout << 0 << " ";
	}

	return 0;
}