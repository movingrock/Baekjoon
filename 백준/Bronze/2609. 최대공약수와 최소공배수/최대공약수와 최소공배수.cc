#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	if (b > a) {
		int tmp = b;
		b = a;
		a = tmp;
	}

	cout << gcd(a, b) << "\n" << a * b / gcd(a, b);

	return 0;
}