#include <iostream>
#include <queue>
using namespace std;

int m, n;
int grid[1000][1000];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m; 
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && grid[nx][ny] == 0) {
				grid[nx][ny] = grid[x][y] + 1; // 값으로 날짜를 넣어줌.
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) q.push(make_pair(i, j));
		}
	}


	bfs();

	bool allRipen = true;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) allRipen = false;
			ans = max(ans, grid[i][j]);
		}
	}

	if (allRipen) cout << ans-1;
	else cout << "-1";

	return 0;
}