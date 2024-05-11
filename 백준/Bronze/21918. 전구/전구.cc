#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	int arr[4001];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) arr[b] = c;
		else if (a == 2) {
			for (int j = b; j <= c; j++) {
				if (arr[j] == 1) arr[j] = 0;
				else arr[j] = 1;
			}
		}
		else if (a == 3) {
			for (int j = b; j <= c; j++) {
				arr[j] = 0;
			}
		}
		else if (a == 4) {
			for (int j = b; j <= c; j++) {
				arr[j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}