#include <iostream>

using namespace std;

bool NotSelfNumber[10001];

int dFunc(int n) {
	int sum = n;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 1; i < 10001; i++) {
		int n = dFunc(i);
		if (n < 10001) {
			NotSelfNumber[n] = true;
		}

	}

	for (int i = 1; i < 10001; i++) {
		if (!NotSelfNumber[i]) cout << i << endl;
	}

	return 0;
}