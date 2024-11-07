#include <iostream>
#include <map>

using namespace std;

char grid[1001][1001];
map<char, pair<int, int>> dir;

bool dfs(int x, int y) {
	if (grid[x][y] == 0) return true;
	else if (grid[x][y] == 1) return false;

	char c = grid[x][y];
	grid[x][y] = 0;
	bool res = dfs(x + dir[c].first, y + dir[c].second);
	grid[x][y] = 1;

	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	dir.insert({ 'U', { -1, 0 } });
	dir.insert({ 'D', { 1, 0 } });
	dir.insert({ 'L', { 0, -1 } });
	dir.insert({ 'R', { 0, 1 } });

	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) answer++;
		}
	}

	cout << answer;

	return 0;
}