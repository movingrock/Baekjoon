#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int factorial(int n) {
	int num = 1;
	for (int i = 2; i < n + 1; i++) num *= i;

	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout << factorial(n) / factorial(k) / factorial(n - k);

	return 0;
}