#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, t, p;
	int arr[6];

	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	cin >> t >> p;

	int cnt1 = 0;
	for (int i = 0; i < 6; i++) {
		cnt1 += arr[i] / t;

		if(arr[i] % t != 0) cnt1 += 1;
	}

	cout << cnt1 << "\n" << n / p << " " << n % p;

	return 0;
}