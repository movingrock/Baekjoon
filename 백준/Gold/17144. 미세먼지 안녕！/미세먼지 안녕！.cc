#include <iostream>

using namespace std;

int r, c, t;
int grid[51][51] = { 0, };
int grid_copy[51][51] = { 0, };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

pair<int, int> up;
pair<int, int> down;


bool InRange(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

void Diffuse() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			grid_copy[i][j] = 0;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == -1) {
				grid_copy[i][j] = grid[i][j];
			}
			else {
				int amount = grid[i][j] / 5;
				int canDiffuse = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (InRange(nx, ny) && grid[nx][ny] != -1) {
						canDiffuse++;
						grid_copy[nx][ny] += amount;
					}
				}
				grid_copy[i][j] += (grid[i][j] - (amount * canDiffuse));
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			grid[i][j] = grid_copy[i][j];
		}
	}
}

void Cleaner() {
	// 위쪽
	for (int i = up.first-1; i > 0; i--) {
		grid[i][0] = grid[i-1][0];
	}
	
	for (int i = 0; i < c-1; i++) {
		grid[0][i] = grid[0][i + 1];
	}

	for (int i = 0; i < up.first; i++) {
		grid[i][c-1] = grid[i + 1][c-1];
	}

	for (int i = c; i > 1; i--) {
		grid[up.first][i] = grid[up.first][i - 1];
	}
	grid[up.first][1] = 0;

	// 아래쪽
	for (int i = down.first + 1; i < r-1; i++) {
		grid[i][0] = grid[i+1][0];
	}

	for (int i = 0; i < c-1; i++) {
		grid[r - 1][i] = grid[r - 1][i + 1];
	}

	for (int i = r - 1; i > down.first; i--) {
		grid[i][c - 1] = grid[i - 1][c - 1];
	}

	for (int i = c - 1; i > 1; i--) {
		grid[down.first][i] = grid[down.first][i - 1];
	}
	grid[down.first][1] = 0;
}

int main(int argc, char** argv)
{
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == -1) {
				down = { i, j };
			}
		}
	}
	up = { down.first - 1, down.second };

	while (t--) {
		Diffuse();
		Cleaner();
	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] != -1) ans += grid[i][j];
		}
	}
	cout << ans;
	return 0;
}