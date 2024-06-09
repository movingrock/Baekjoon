#include <iostream>

using namespace std;
int grid[19][19];

bool InRange(int x, int y) {
	return x >= 0 && x < 19 && y >= 0 && y < 19;
}

bool Check(int x, int y) {
	// 대각선 ( \ )
	{
		int num = grid[x][y];
		int cnt = 1;
		int nx = x+1;
		int ny = y+1;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; nx++; ny++;
			}
			else break;
		}
		nx = x-1;
		ny = y-1;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; nx--; ny--;
			}
			else break;
		}
		if (cnt == 5) return true;
	}
	// 대각선 ( / )
	{
		int num = grid[x][y];
		int cnt = 1;
		int nx = x+1;
		int ny = y-1;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; nx++; ny--;
			}
			else break;
		}
		nx = x-1;
		ny = y+1;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; nx--; ny++;
			}
			else break;
		}
		if (cnt == 5) return true;
	}
	// 가로
	{
		int num = grid[x][y];
		int cnt = 1;
		int nx = x;
		int ny = y+1;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; ny++;
			}
			else break;
		}
		nx = x;
		ny = y-1;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; ny--;
			}
			else break;
		}
		if (cnt == 5) return true;
	}
	// 세로
	{
		int num = grid[x][y];
		int cnt = 1;
		int nx = x+1;
		int ny = y;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; nx++;
			}
			else break;
		}
		nx = x-1;
		ny = y;
		while (true) {
			if (!InRange(nx, ny)) break;
			if (grid[nx][ny] == num) {
				cnt++; nx--;
			}
			else break;
		}
		if (cnt == 5) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> grid[i][j];
		}
	}

	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < 19; i++) {
			if (grid[i][j] == 0) continue;
			if (Check(i, j)) {
				cout << grid[i][j] << "\n" << i+1 << " " << j+1;
				return 0;
			}
		}
	}

	cout << 0;

	return 0;
}