#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int grid[25][25] = { 0, };
int visited[25][25] = { 0, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;
vector<int> v;
int number = 1;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 1;
	while (!q.empty()) {
		grid[x][y] = number;
		visited[x][y] = true;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (grid[nx][ny] == 1 && InRange(nx, ny) && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				grid[nx][ny] = number;
				cnt++;
			}
		}
	}
	number++;
	v.push_back(cnt);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			grid[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(grid[i][j] == 1 && !visited[i][j]) bfs(i, j);
		}
	}


	sort(v.begin(), v.end());

	cout << number - 1 << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}