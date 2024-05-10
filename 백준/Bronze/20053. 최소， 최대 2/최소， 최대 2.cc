#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;
		while (n--) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		cout << v[0] << " " << v[v.size() - 1] << "\n";
	}

	return 0;
}