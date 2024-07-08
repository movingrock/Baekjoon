#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool visited[51][51];
int grid[51][51];
int n, l, r;

bool InRange(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

void Initialize() {
	memset(visited, false, sizeof(visited));
}

bool bfs(int sx, int sy, bool isMoved) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> answer;
	q.push({ sx, sy });
	visited[sx][sy] = true;
	answer.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int diff = abs(grid[nx][ny] - grid[x][y]);
			if (InRange(nx, ny) && !visited[nx][ny] && diff >= l && diff <= r) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
				answer.push({ nx, ny });
				isMoved = true;
			}
		}
	}
	if (answer.size() == 1) return false;

	int sum = 0;
	int cnt = answer.size();
	queue<pair<int, int>> tmp;
	tmp = answer;
	while (!answer.empty()) {
		int x = answer.front().first;
		int y = answer.front().second;

		answer.pop();
		sum += grid[x][y];
	}

	if(cnt != 0) sum /= cnt;
	
	while (!tmp.empty()) {
		int x = tmp.front().first;
		int y = tmp.front().second;
		grid[x][y] = sum;
		tmp.pop();
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int day = 0;

	while (true) {
		bool isMoved = false;
		Initialize();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					if (bfs(i, j, isMoved)) isMoved = true;
				}
			}
		}

		if (!isMoved) break;

		day++;
	}

	cout << day;
	return 0;
}