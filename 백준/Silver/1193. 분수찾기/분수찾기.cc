#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x;
	cin >> x;
	int right = 1;
	while (x > right) {
		x -= right;
		right++;
	}

	if (right % 2 == 1) cout << right - x + 1<< "/" << x;
	else cout << x << "/" << right + 1 - x;

	return 0;
}