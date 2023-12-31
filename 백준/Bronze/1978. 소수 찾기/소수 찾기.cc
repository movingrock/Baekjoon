#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		bool isPrime = true;
		for (int j = 2; j < num; j++) {
			if (num % j == 0) isPrime = false;
		}

		if (num >= 2 && isPrime) cnt++;
	}
	
	cout << cnt;

	return 0;
}