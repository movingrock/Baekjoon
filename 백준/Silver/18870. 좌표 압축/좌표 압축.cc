#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v1.push_back(x);
		v2.push_back(x);
	}

	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << " ";
	}
	

	return 0;
}