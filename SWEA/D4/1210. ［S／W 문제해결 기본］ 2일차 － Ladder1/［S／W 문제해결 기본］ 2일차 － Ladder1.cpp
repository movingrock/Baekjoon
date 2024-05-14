#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int grid[100][100];
int answer = 0;
bool findRoute = false;

void dfs(int x, int y) {
	if (x == 0) {
		findRoute = true;
		answer = y;
		return;
	}
	if (y >= 1 && grid[x][y - 1] == 1) {
		while (grid[x][y] == 1 && y>=0) {
			y--;
		}
		dfs(x - 1, y+1);
	}
	else if (y <= 98 && grid[x][y + 1] == 1) {
		while (grid[x][y] == 1 && y<=99) {
			y++;
		}
		dfs(x - 1, y-1);
	}
	else if (grid[x - 1][y] == 1) {
		dfs(x - 1, y);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc; cin >> tc;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> grid[i][j];
			}
		}

		findRoute = false;
		for (int i = 0; i < 100; i++) {
			if (grid[99][i] == 2) {
				dfs(99, i);

				if (findRoute) {
					cout << "#" << test_case << " " << answer << endl;
					break;
				}
			}
		}
	}
	return 0;
}