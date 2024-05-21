#include <iostream>

using namespace std;
long long MOD = 1000000007;

long long f(long long x, long long y) {
	if (y == 1) return x;
	if (y % 2 == 1) return x * f(x, y - 1) % MOD;
	long long p = f(x, y / 2);
	return p * p % MOD;
}

long long GCD(long long a, long long b) {
	long long temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}

	long long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long m, a, b;
	long long ans = 0;

	cin >> m;

	while (m--) {
		cin >> a >> b;
		long long g = GCD(a, b);
		a /= g;
		b /= g;
		ans += b * f(a, MOD - 2) % MOD;
		ans %= MOD;
	}

	cout << ans;

	return 0;
}