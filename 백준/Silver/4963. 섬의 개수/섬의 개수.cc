#include <iostream>
#include <queue>

using namespace std;

int grid[51][51];
bool visited[51][51];

int dx[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int dy[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int w, h;

void Initialize() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = 0;
		}
	}
}

bool InRange(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w;
}

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true) {
		int answer = 0;

		cin >> w >> h;
		if (w == 0 && h == 0) break;
		Initialize();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> grid[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (grid[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}