#include <iostream>

using namespace std;
#define INF 99999999

int grid[101][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	int a, b, c;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) grid[i][j] = 0;
			else grid[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		grid[a][b] = min(grid[a][b], c);
	}

	for (int k = 1; k <= n; k++) { // 중간 도시
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (grid[i][j] == INF) cout << 0 << " ";
			else cout << grid[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}