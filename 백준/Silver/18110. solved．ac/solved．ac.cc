#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n = 0;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	int ex = round(n * 0.15);
	double sum = 0;

	for (int i = ex; i < n - ex; i++) sum += v[i];

	int result = round(sum / (n - ex * 2));

	if (n) cout << result;
	else cout << 0;

	return 0;
}