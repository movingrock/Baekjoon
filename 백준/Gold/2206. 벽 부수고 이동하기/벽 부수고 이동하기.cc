#include <iostream>
#include <queue>

using namespace std;

int grid[1001][1001];
bool visited[1001][1001][2];
int n, m;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
	visited[0][0][0] = true;
	visited[0][0][1] = true;
	queue<pair<pair<int, int>, pair<int, int>>> q; // {x, y}  {벽 부수기, cnt}
	q.push({ {0, 0},{0, 1}});

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first; // 0이면 아직 안 부쉈고, 1이면 이미 벽을 부쉈음.
		int cnt = q.front().second.second;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (InRange(nx, ny) && !visited[nx][ny][wall]) {
				if (wall == 0 && grid[nx][ny] == 0) {
					visited[nx][ny][wall] = true;
					q.push({ { nx, ny }, { 0, cnt + 1 } });
				}
				else if (wall == 0 && grid[nx][ny] == 1) {
					visited[nx][ny][wall] = true;
					q.push({ { nx, ny }, { 1, cnt + 1 } });

				}
				else if (wall == 1 && grid[nx][ny] == 0) {
					visited[nx][ny][wall] = true;
					q.push({ { nx, ny }, { 1, cnt + 1 } });
				}
			}
		}

	}
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			grid[i][j] = str[j] - '0';
		}
	}

	bfs();

	return 0;
}