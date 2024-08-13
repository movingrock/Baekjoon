#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

#define INF INT_MAX;

using namespace std;

int n, m;
int grid[101][101];
int dist[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
	queue<pair<int, int>> q;
	dist[0][0] = 0;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny)) {
				if (dist[nx][ny] > dist[x][y] + 1 && grid[nx][ny] == 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
				else if (dist[nx][ny] > dist[x][y] && grid[nx][ny] == 0) {
					dist[nx][ny] = dist[x][y];
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			grid[i][j] = str[j] - '0';
			dist[i][j] = INF;
		}
	}

	bfs();

	cout << dist[n - 1][m - 1];


	return 0;
}