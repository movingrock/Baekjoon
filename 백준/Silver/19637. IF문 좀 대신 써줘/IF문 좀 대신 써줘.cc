#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	multimap<int, string> power;
	for (int i = 0; i < n; i++) {
		string s; int pow;
		cin >> s >> pow;
		power.insert({ pow, s });
	}

	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;
		cout << power.lower_bound(c)->second << "\n";
	}

	return 0;
}