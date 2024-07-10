#include <iostream>

using namespace std;

int grid[501][501];
int dp[501][501];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int n, m;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int DFS(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && grid[x][y] > grid[nx][ny]) {
			dp[x][y] += DFS(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(0, 0);

	return 0;
}