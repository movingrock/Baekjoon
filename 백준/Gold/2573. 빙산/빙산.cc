#include <iostream>
#include <queue>

using namespace std;

int grid[301][301];
int copy_grid[301][301];
bool visited[301][301];
int n, m;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool allZero() {
	bool allZero = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] != 0) allZero = false;
		}
	}
	return allZero;
}

bool bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] != 0) {
				queue<pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] != 0) {
							visited[nx][ny] = true;
							q.push({ nx, ny });
						}
					}
				}
				flag = true;
			}
			if (flag) break;
		}
		if (flag) break;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] != 0 && !visited[i][j]) return true;
		}
	}
	
	return false;
}

void Melting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				copy_grid[i][j] = 0;
				continue;
			}

			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (InRange(nx, ny) && grid[nx][ny] == 0) cnt++;
			}
			copy_grid[i][j] = grid[i][j] - cnt <= 0 ? 0 : grid[i][j] - cnt;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			grid[i][j] = copy_grid[i][j];
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

	int answer = 0;

	while (true) {
		Melting();
		if (allZero()) {
			answer = 0;
			break;
		}
		answer++;
		if (bfs()) break;
	}

	cout << answer;

	return 0;
}

