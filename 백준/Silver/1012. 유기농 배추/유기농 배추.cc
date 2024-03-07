#include <iostream>

using namespace std;

int t, m, n, k;
int grid[50][50] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
	grid[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		if (!InRange(x + dx[i], y + dy[i])) continue;
		if (grid[x + dx[i]][y + dy[i]] == 1) dfs(x + dx[i], y + dy[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		int cnt = 0;

		// 초기화
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				grid[j][k] = 0;
			}
		}

		// 배추 위치
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> y >> x;
			grid[x][y] = 1;
		}

		// 탐색
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (grid[j][k] == 1) {
					dfs(j, k);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

	}

	return 0;
}