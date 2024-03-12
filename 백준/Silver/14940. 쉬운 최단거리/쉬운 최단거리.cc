#include <iostream>
#include <queue>
using namespace std;

int m, n;
int grid[1000][1000];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;
bool visited[1000][1000] = { 0, };


bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m; 
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
				grid[nx][ny] = grid[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 2) { q.push(make_pair(i, j)); grid[i][j] = 0; }
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1 && !visited[i][j]) cout << "-1 ";
			else cout << grid[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}