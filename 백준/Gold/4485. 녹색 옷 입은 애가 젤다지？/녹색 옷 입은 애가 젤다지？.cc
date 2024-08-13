#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

#define INF INT_MAX;

using namespace std;

int n;
int grid[126][126];
int dist[126][126];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs() {
	queue<pair<int, int>> q;
	dist[0][0] = grid[0][0];
	q.push({ 0, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny)) {
				if (dist[nx][ny] > dist[x][y] + grid[nx][ny]) {
					dist[nx][ny] = dist[x][y] + grid[nx][ny];
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int num = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				dist[i][j] = INF;
			}
		}

		bfs();

		cout << "Problem " << num++ << ": " << dist[n - 1][n - 1] << "\n";
	}





	return 0;
}