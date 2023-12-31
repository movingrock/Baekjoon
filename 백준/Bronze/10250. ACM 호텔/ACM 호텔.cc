#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	int floor = 0;
	int roomNum = 0;
	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;
		if (n % h == 0) cout << h * 100 + n / h << "\n";
		else cout << n % h * 100 + n / h + 1 << "\n";
	}

	return 0;
}