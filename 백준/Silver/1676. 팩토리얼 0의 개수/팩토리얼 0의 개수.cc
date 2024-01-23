#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	int cnt2 = 0;
	int cnt5 = 0;
	for (int i = 2; i <= n; i++) {
		int num = i;
		while (num % 2 == 0) {
			cnt2++;
			num /= 2;
		}
		while (num % 5 == 0) {
			cnt5++;
			num /= 5;
		}
	}
	cout << min(cnt2, cnt5);
	return 0;
}