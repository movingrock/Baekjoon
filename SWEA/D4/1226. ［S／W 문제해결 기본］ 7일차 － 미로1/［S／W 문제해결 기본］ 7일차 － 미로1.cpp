#include <iostream>
#include <queue>

using namespace std;

int grid[16][16];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


bool InRange(int x, int y) {
	return x >= 0 && x <= 15 && y >= 0 && y <= 15;
}

bool bfs() {
	int visited[16][16] = { 0, };
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visited[1][1] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (grid[x][y] == 3) return true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] != 1) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}

		}
	}
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc; cin >> tc;
		for (int i = 0; i < 16; i++) {
			string str; cin >> str;
			for (int j = 0; j < 16; j++) {
				grid[i][j] = (str[j] - '0');
			}
		}

		if(bfs()) cout << "#" << test_case << " " << 1 << endl;
		else cout << "#" << test_case << " " << 0 << endl;
	
	}
	return 0;
}