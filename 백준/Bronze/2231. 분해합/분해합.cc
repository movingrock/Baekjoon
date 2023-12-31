#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int sum = 0;
		int num = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (i + sum == n) { answer = i; break; }
	}

	cout << answer;

	return 0;
}