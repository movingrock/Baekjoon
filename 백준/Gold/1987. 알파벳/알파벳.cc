#include <iostream>

using namespace std;

char grid[21][21];
int r, c;
bool visited[27]; // 0은 a 26은 z

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int ans = 0;

bool InRange(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}


void dfs(int x, int  y, int cnt) {
	char board = grid[x][y];

	ans = max(cnt, ans);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (InRange(nx, ny)  && !visited[grid[nx][ny] - 'A']) {
			visited[grid[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			visited[grid[nx][ny] - 'A'] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	string str;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			grid[i][j] = str[j];
		}
	}

	visited[grid[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << ans;

	return 0;
}