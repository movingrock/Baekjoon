#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int grid[8][8];
int grid_copy[8][8];
bool visited[8][8] = { 0, };
int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> virus;
int ans = 0;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			grid_copy[i][j] = grid[i][j];
			visited[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first, virus[i].second });
		visited[virus[i].first][virus[i].second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) &&  grid_copy[nx][ny] == 0 && !visited[nx][ny]) {
				grid_copy[nx][ny] = 2;
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid_copy[i][j] == 0) cnt++;
			//cout << grid_copy[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
	//cout << cnt << endl;
	ans = max(ans, cnt);

}

void Wall(int x) {
	if (x == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				grid[i][j] = 1;
				Wall(x + 1);
				grid[i][j] = 0;
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
			if (grid[i][j] == 2) virus.push_back({ i, j });
		}
	}

	Wall(0);

	cout << ans;

	return 0;
}

// backtracking으로 3곳 막기
// 막은후 2를 bfs로 감염시키기
// 0 개수세기