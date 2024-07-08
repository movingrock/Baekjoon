#include <iostream>
#include <climits>

using namespace std;

int n;
int grid[101][101];
bool visited[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int max_num = INT_MIN;

void Initialize() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y, int limit) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && grid[nx][ny] > limit && !visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, limit);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			max_num = max(max_num, grid[i][j]);
		}
	}
	int answer = 0;
	for (int x = 0; x <= max_num; x++) {
		Initialize();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (x < grid[i][j] && !visited[i][j]) { dfs(i, j, x); cnt++; }
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer;

	return 0;
}