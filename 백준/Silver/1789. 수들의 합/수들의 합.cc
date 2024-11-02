#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long s;
	cin >> s;
	long long n = 1;
	long long sum = n;

	while (true) {
		if (sum > s) {
			n--;
			break;
		}
		n++;
		sum += n;
	}
	cout << n;

	return 0;
}