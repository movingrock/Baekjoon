#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int arr[101];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int n2;
	cin >> n2;

	for (int i = 0; i < n2; i++) {
		int s, num;
		cin >> s >> num;

		if (s == 1) {
			for (int i = 1; i <= n; i++) {
				if (i % num == 0) {
					if (arr[i] == 1) arr[i] = 0;
					else if (arr[i] == 0) arr[i] = 1;
				}
			}
		}
		else if (s == 2) {
			if (arr[num] == 1) arr[num] = 0;
			else if (arr[num] == 0) arr[num] = 1;
			for (int i = 1; arr[num - i] == arr[num + i]; i++) {
				if (num - i <1 || num + i > n) break;
				if (arr[num - i] == 1) arr[num - i] = 0;
				else if (arr[num - i] == 0) arr[num - i] = 1;

				if (arr[num + i] == 1) arr[num + i] = 0;
				else if (arr[num + i] == 0) arr[num + i] = 1;
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}

	return 0;
}