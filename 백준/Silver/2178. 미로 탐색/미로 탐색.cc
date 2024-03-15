#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

#define MAXN 101

using namespace std;

int grid[MAXN][MAXN] = { 0, };
int visited[MAXN][MAXN] = { 0, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;
vector<int> v;

bool InRange(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (grid[nx][ny] == 1 && InRange(nx, ny) && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				grid[nx][ny] = grid[x][y] + 1;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			grid[i][j+1] = str[j] - '0';
		}
	}

	bfs(1, 1);

	cout << grid[n][m];

	return 0;
}