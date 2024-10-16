#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> grid(9, vector<int>(9));

int answer = INT_MAX;
vector<pair<int, pair<int, int>>> cctv; // cctv 리스트 {번호, {x좌표, y좌표}}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void check(int x, int y, int dir) {
	dir %= 4;
	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (!InRange(x, y) || grid[x][y] == 6) return;
		if (grid[x][y] != 0) continue;
		grid[x][y] = 7;
	}
}

void backtracking(int num) {
	if (num == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}

	int cctvNum = cctv[num].first;
	int x = cctv[num].second.first;
	int y = cctv[num].second.second;
	vector<vector<int>> tmp_grid(9, vector<int>(9));

	tmp_grid = grid;

	for (int dir = 0; dir < 4; dir++) {
		switch (cctvNum)
		{
		case 1:
			check(x, y, dir);
			break;
		case 2:
			check(x, y, dir);
			check(x, y, dir+2);
			break;
		case 3:
			check(x, y, dir);
			check(x, y, dir + 1);
			break;
		case 4:
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			break;
		case 5:
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
			break;
		default:
			break;
		}

		backtracking(num + 1);

		grid = tmp_grid;

	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] != 0 && grid[i][j] != 6) cctv.push_back({grid[i][j], {i, j}});
		}
	}

	backtracking(0);

	cout << answer;

	return 0;
}