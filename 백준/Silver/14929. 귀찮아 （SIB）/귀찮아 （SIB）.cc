#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	long long answer = 0;
	long long prefixSum = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		answer += x * prefixSum;
		prefixSum += x;
	}

	cout << answer;

	return 0;
}