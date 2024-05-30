#include <iostream>

using namespace std;

int grid[999][999];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dir = 3;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, findNum;
	cin >> n >> findNum;

	int fx = -1;
	int fy = -1;

	int sx = (n - 1) / 2;
	int sy = (n - 1) / 2;

	int x = (n - 1) / 2;
	int y = (n - 1) / 2;

	int cnt = 1;
	int length = 0;
	for (int i = 1; i <= n * n; i++) {
		grid[x][y] = i;
		if (i == cnt*cnt) {
			x -= 1;
			length += 1;
			cnt += 2;
			dir = (dir + 1) % 4;
			continue;
		}


		if (x == sx - length && y == sy + length) {
			dir = (dir + 1) % 4;
		}
		else if (x == sx + length && y == sy + length) {
			dir = (dir + 1) % 4;
		}
		else if (x == sx + length && y == sy - length) {
			dir = (dir + 1) % 4;
		}
		else if (x == sx - length && y == sy - length) {
			dir = (dir + 1) % 4;
		}
		x += dx[dir];
		y += dy[dir];


	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == findNum) {
				fx = i; fy = j;
			}
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}

	cout << fx + 1 << " " << fy + 1;

	return 0;
}