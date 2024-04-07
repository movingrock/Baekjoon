#include <iostream>
#include <map>

#define MOD 1000000007

using namespace std;

map<long long, long long> m;

long long fibo(long long n) {
	if (m[n] > 0) return m[n];
	long long result;
	if (n % 2 == 0) result = (fibo(n / 2) * (fibo(n / 2 + 1) + fibo(n / 2 - 1))) % MOD;
	else result = ((fibo((n + 1) / 2) * fibo((n + 1) / 2)) % MOD) + ((fibo((n - 1) / 2) * fibo((n - 1) / 2)) % MOD) % MOD;

	return m[n] = result % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	unsigned long long n;
	cin >> n;
	
	m[0] = 0;
	m[1] = 1;
	m[2] = 1;

	cout << fibo(n);

	return 0;
}