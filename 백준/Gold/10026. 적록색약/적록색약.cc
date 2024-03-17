#include <iostream>
#include <queue>

using namespace std;

char grid[101][101];
char gridRG[101][101];
bool visited[101][101];
bool visitedRG[101][101];
int n;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny)&& !visited[nx][ny] && grid[a][b] == grid[nx][ny]) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void bfsRG(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visitedRG[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visitedRG[nx][ny] && gridRG[a][b] == gridRG[nx][ny]) {
				visitedRG[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			grid[i][j] = str[j];
			gridRG[i][j] = str[j];
			if (gridRG[i][j] == 'G') gridRG[i][j] = 'R';
		}
	}

	int cnt = 0;
	int cntRG = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) { bfs(i, j); cnt++; }
			if (!visitedRG[i][j]) { bfsRG(i, j); cntRG++; }
		}
	}

	cout << cnt << " " << cntRG;

	return 0;
}