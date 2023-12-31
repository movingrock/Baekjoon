#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	long long sum = 0;
	int digit = 0;
	for (int i = 0; i < n; i++) {
		sum += (s[i] - 'a' + 1) * pow(31, digit);
		digit++;
	}

	cout << sum;

	return 0;
}