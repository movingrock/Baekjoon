#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> prime;
	vector<bool> isPrime(n+1, 1);

	for (int i = 2; i * i <= n; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			isPrime[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) prime.push_back(i);
	}

	int start = 0;
	int end = 0;
	int answer = 0;
	int sum = 0;
	while (true) {
		if (sum >= n) sum -= prime[start++];
		else if (end == prime.size()) break;
		else sum += prime[end++];

		if (sum == n) answer++;

	}

	cout << answer;


	return 0;
}