#include <iostream>
#include <algorithm>

using namespace std;

bool Func(int num) {
	int cnt = 0;
	while (num != 0) {
		if (num % 10 == 6) cnt++;
		else cnt = 0;

		num /= 10;

		if (cnt == 3) return true;
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	int num = 0;
	while (true) {
		if (Func(num)) cnt++;
		if (cnt == n) break;
		num++;
	}
	cout << num;
	return 0;
}