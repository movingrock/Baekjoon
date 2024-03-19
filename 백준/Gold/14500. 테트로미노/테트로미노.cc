#include <iostream>

using namespace std;

int n, m;
int grid[501][501];
bool visited[501][501];
int ans = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 3) {
		ans = max(ans, sum); return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (InRange(nx, ny) && !visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1, sum + grid[nx][ny]);
			visited[nx][ny] = false;
		}
	}
}

void fshape(int x, int y) {
	if (InRange(x - 1, y) && InRange(x + 1, y) && InRange(x, y + 1)) ans = max(ans, grid[x][y] + grid[x - 1][y] + grid[x + 1][y] + grid[x][y + 1]);
	if (InRange(x - 1, y) && InRange(x + 1, y) && InRange(x, y - 1)) ans = max(ans, grid[x][y] + grid[x - 1][y] + grid[x + 1][y] + grid[x][y - 1]);
	if (InRange(x, y - 1) && InRange(x, y + 1) && InRange(x - 1, y)) ans = max(ans, grid[x][y] + grid[x][y - 1] + grid[x][y + 1] + grid[x - 1][y]);
	if (InRange(x, y - 1) && InRange(x, y + 1) && InRange(x + 1, y)) ans = max(ans, grid[x][y] + grid[x][y - 1] + grid[x][y + 1] + grid[x + 1][y]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 0, grid[i][j]);
			fshape(i, j);
			visited[i][j] = false;

		}
	}

	cout << ans;

	return 0;
}