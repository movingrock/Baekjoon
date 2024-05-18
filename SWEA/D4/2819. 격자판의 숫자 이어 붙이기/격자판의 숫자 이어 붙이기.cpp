#include<iostream>
#include <string>
#include <set>
using namespace std;

int grid[4][4];
set<string> s;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void dfs(string str, int x, int y) {
	str += to_string(grid[x][y]);

	if (str.length() == 7) {
		s.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (InRange(nx, ny)) {
			dfs(str, nx, ny);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> grid[i][j];
			}
		}
		s.clear();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs("", i, j);
			}
		}

		cout << "#" << test_case << " " << s.size() << endl;
	}
	return 0;
}