#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	unsigned long long n;
	cin >> n;

	unsigned long long q = sqrt(n);
	if (q * q < n) {
		q++;
	}

	cout << q;

	return 0;
}