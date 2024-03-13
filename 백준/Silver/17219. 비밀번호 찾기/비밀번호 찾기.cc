#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, string> map;

	for (int i = 0; i < n; i++) {
		string site, password;
		cin >> site >> password;
		map[site] = password;
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		cout << map[str] << '\n';
	}

	return 0;
}