#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int l = lcm(m, n);

		int cnt = -1;

		for (int j = x; j <= l; j += m) {
			int yy = j % n;

			if (yy == 0) yy = n;

			if (yy == y) {
				cnt = j;
				break;
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}