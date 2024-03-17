#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m, n, h;

int grid[101][101][101];
bool visited[101][101][101];

int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct Point {
	int z;
	int x;
	int y;
};

queue<Point> q;

bool InRange(int z, int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < h;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		visited[z][x][y] = true;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (InRange(nz, nx, ny)&& !visited[nz][nx][ny] && grid[nz][nx][ny] == 0) {
				visited[nz][nx][ny] = true;
				q.push({ nz, nx, ny });
				grid[nz][nx][ny] = grid[z][x][y] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool startRotten = true;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> grid[i][j][k];
				if (grid[i][j][k] == 1) q.push({i, j, k});
				if (grid[i][j][k] == 0) startRotten = false;
			}
		}
	}

	bfs();

	int max_day = 0;
	bool isAllRotten = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (grid[i][j][k] == 0) isAllRotten = false;
				max_day = max(max_day, grid[i][j][k]);
			}
		}
	}

	if (startRotten) cout << 0;
	else if (!startRotten && !isAllRotten) cout << -1;
	else cout << max_day - 1;

	return 0;
}