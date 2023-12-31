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
	long long r = 1;
	long long M = 1234567891;
	for (int i = 0; i < n; i++) {
		sum += (((s[i] - 'a' + 1) * r) % M);
		sum %= M;
		r = (r * 31) % M;
	}

	cout << sum;

	return 0;
}