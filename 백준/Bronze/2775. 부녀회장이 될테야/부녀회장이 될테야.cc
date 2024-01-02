#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	int grid[15][15] = { 0, };

	for (int j = 0; j < 15; j++) {
		grid[0][j] = j;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int k = 1; k <= j; k++) {
				grid[i][j] += grid[i - 1][k];
			}
		}
	}

	for (int i = 0; i < t; i++) {
		int k, n;
		cin >> k >> n;
		cout << grid[k][n] << "\n";
	}

	return 0;
}