#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	int remain[42] = {0, };
	for (int i = 0; i < 10; i++) {
		cin >> num;
		remain[num % 42]++;
	}

	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (remain[i] > 0) cnt++;
	}

	cout << cnt;

	return 0;
}