#include <iostream>
#include <queue>

using namespace std;

int n, m;
char grid[11][11];
bool visited[11][11][11][11];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int answer = -1;
int rx, ry, bx, by;

struct board {
	int rx, ry, bx, by, cnt;
};

void move(int& x, int& y, int& c, int& i) {
	while (grid[x + dx[i]][y + dy[i]] != '#' && grid[x][y] != 'O') {
		x += dx[i];
		y += dy[i];
		c += 1;
	}
}

void bfs() {
	queue<board> q;
	q.push({ rx, ry, bx, by, 0 });
	visited[rx][ry][bx][by] = true;

	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt >= 10) return;

		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;
			int rc = 0;
			int bc = 0;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (grid[nbx][nby] == 'O') continue;
			if (grid[nrx][nry] == 'O') {
				answer = cnt + 1;
				return;
			}

			if (nrx == nbx && nry == nby) {
				if (rc > bc) { 
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({ nrx, nry, nbx, nby, cnt + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			grid[i][j] = str[j];
			if (grid[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			if (grid[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}

	bfs();

	cout << answer;

	return 0;
}