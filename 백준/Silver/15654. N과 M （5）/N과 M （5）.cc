#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int input[9];
bool visited[9];
int n, m;

void backtracking(int cnt, int x) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			arr[cnt] = input[i];
			visited[i] = true;
			backtracking(cnt + 1, x + 1);
			visited[i] = false;
		}

	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);

	backtracking(0, 0);

	return 0;
}