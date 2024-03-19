#include <iostream>

using namespace std;

int arr[9];
int n, m;

void backtracking(int cnt, int x) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = x; i <= n; i++) {
		arr[cnt] = i;
		backtracking(cnt + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	backtracking(0, 1);

	return 0;
}