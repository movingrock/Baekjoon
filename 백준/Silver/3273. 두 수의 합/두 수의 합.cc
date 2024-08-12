#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x;

	sort(v.begin(), v.end());

	int answer = 0;
	int start = 0;
	int end = n - 1;
	while (start < end) {
		if (v[start] + v[end] == x) {
			answer++;
			start++;
			end--;
		}
		else if (v[start] + v[end] > x) {
			end--;
		}
		else {
			start++;
		}
	}

	cout << answer;

	return 0;
}