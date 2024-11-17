#include <iostream>

#define MAX 501 

using namespace std;

int grid[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (grid[i][k] + grid[k][j] < grid[i][j]) grid[i][j] = grid[i][k] + grid[k][j];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (grid[a][b] <= c) cout << "Enjoy other party\n";
		else cout << "Stay here\n";
	}


	return 0;
}