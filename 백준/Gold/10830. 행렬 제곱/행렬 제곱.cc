#include <iostream>
using namespace std;

int n;
long long b;

long long grid[5][5] = { 0, };
long long ans[5][5] = { 0, };

void Matrix(long long m1[5][5], long long m2[5][5]) {
	long long tmp[5][5] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += (m1[i][k] * m2[k][j]);
			}
			tmp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m1[i][j] = tmp[i][j];
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) ans[i][j] = 1;
		}
	}

	while (b > 0) {
		if (b % 2 == 1) {
			Matrix(ans, grid);
		}
		Matrix(grid, grid);
		b /= 2;
	}
		

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}