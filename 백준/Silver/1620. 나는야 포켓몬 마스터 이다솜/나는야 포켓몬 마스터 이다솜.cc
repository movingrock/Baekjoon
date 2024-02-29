#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, int> map;
	vector<string> v;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
		map.insert(make_pair(str, i));
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str[0] >= 65 && str[0] <= 90) {
			cout << map.find(str)->second << "\n";
		}
		else {
			cout << v[stoi(str)-1] << "\n";
		}
	}

	return 0;
}