#include <iostream>

using namespace std;

int arr[41][2];

void fibo(int n) {
	if (n == 0) { arr[n][0] = 1; arr[n][1] = 0; }
	else if (n == 1) { arr[n][0] = 0; arr[n][1] = 1; }
	else { arr[n][0] = arr[n - 1][0] + arr[n - 2][0];
		arr[n][1] = arr[n - 1][1] + arr[n - 2][1];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i <= 40; i++) fibo(i);

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << arr[n][0] << " " << arr[n][1] << "\n";
	}
	return 0;
}