#include <iostream>
#include <queue>
using namespace std;

char grid[601][601];
bool visited[601][601] = { 0, };
int n, m;
int a, b;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int ans = 0;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny]) {
				if (grid[nx][ny] == 'O') { q.push(make_pair(nx, ny)); visited[nx][ny] = true;}
				else if (grid[nx][ny] == 'P') { q.push(make_pair(nx, ny)); visited[nx][ny] = true; ans++; }
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
			if (grid[i][j] == 'I') { a = i; b = j; }
		}
	}

	bfs();

	if (ans == 0) cout << "TT";
	else cout << ans;

	return 0;
}