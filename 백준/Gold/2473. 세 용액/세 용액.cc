#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	long long a1 = 0, a2 = 0, a3 = 0;
	long long smallest = LLONG_MAX;
	
	for (int i = 0; i < n - 2; i++) {
		int left = i+1;
		int right = n - 1;

		while (left < right) {
			long long sum = v[i] + v[left] + v[right];
			if (abs(sum) < smallest) {
				smallest = abs(sum);
				a1 = v[i];
				a2 = v[left];
				a3 = v[right];
			}
			if (sum < 0) left++;
			else right--;
		}
	}

	cout << a1 << " " << a2 << " " << a3;

	return 0;
}