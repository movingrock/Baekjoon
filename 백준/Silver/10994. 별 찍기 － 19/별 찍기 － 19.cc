#include <iostream>

using namespace std;

char grid[401][401];

void Backtracking(int n, int start) {
	if (n == 0) return;
	for (int i = start; i < start + 1 + (n - 1) * 4; i++) {
		for (int j = start; j < start + 1 + (n - 1) * 4; j++) {
			if (i == start || i == start + (n - 1) * 4 || j == start || j == start + (n - 1) * 4 ) grid[i][j] = '*';
		}
	}
	Backtracking(n - 1, start + 2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 1 + (n - 1) * 4; i++) {
		for (int j = 0; j < 1 + (n - 1) * 4; j++) {
			grid[i][j] = ' ';
		}
	}


	Backtracking(n, 0);

	for (int i = 0; i < 1 + (n - 1) * 4; i++) {
		for (int j = 0; j < 1 + (n - 1) * 4; j++) {
			cout << grid[i][j];
		}
		cout << "\n";
	}

	return 0;
}