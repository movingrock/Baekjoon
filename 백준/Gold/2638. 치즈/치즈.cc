#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int grid[101][101];
bool visited[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int ans = 0;

bool Check() {
	bool melted = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) melted = false;
		}
	}
	return melted;
}

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
	ans++;
	queue<pair<int, int>> q;
	memset(visited, 0, sizeof(visited));
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (grid[nx][ny]) grid[nx][ny]++;
			if (InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 0) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] >= 3) grid[i][j] = 0;
			else if (grid[i][j] >= 1) grid[i][j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	while (!Check()) bfs();

	cout << ans;

	return 0;
}
