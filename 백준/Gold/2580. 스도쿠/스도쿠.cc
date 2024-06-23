#include <iostream>
#include <vector>

using namespace std;

int grid[9][9];
bool row[9][9];
bool column[9][9];
bool square[9][9];

void Dfs(int n) {
	int x = n / 9;
	int y = n % 9;

	if (n == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	if (grid[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (!row[x][i] && !column[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {
				row[x][i] = true;
				column[y][i] = true;
				square[(x / 3) * 3 + (y / 3)][i] = true;
				grid[x][y] = i;
				Dfs(n + 1);
				row[x][i] = false;
				column[y][i] = false;
				square[(x / 3) * 3 + (y / 3)][i] = false;
				grid[x][y] = 0;
			}
		}
	}
	else Dfs(n + 1);

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> grid[i][j];

			if (grid[i][j] != 0) {
				row[i][grid[i][j]] = true;
				column[j][grid[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][grid[i][j]] = true;
			}
		}
	}

	Dfs(0);

	return 0;
}