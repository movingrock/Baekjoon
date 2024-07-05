#include <iostream>

using namespace std;

int n, m;
int x, y, d;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int grid[51][51];

int answer = 0;
bool isEnd = false;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void Clean() {
	if (grid[x][y] == 0) { answer++; grid[x][y] = 2; }

	bool allCleaned = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (grid[nx][ny] == 0) allCleaned = false;
	}
	if (!allCleaned) { 
		d = (d + 3) % 4;
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (InRange(nx, ny) && grid[nx][ny] == 0) {
			x = nx;
			y = ny;
		}
	}
	else {
		int bx = x - dx[d];
		int by = y - dy[d];
		if (InRange(bx, by) && grid[bx][by] != 1) {
			x = bx;
			y = by;
		}
		else {
			isEnd = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	while (!isEnd) {
		Clean();
	}


	cout << answer;

	return 0;
}