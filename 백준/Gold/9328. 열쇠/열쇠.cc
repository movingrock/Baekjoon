#include <iostream>
#include <cstring>
#include <queue>

#define MAXN 103

using namespace std;

char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool keyArr[26];
int answer = 0;
int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}

// A 65
// a 97

void Initialize() {
	answer = 0;
	memset(visited, false, sizeof(visited));
	memset(keyArr, false, sizeof(keyArr));
	memset(grid, 0, sizeof(grid));
}

void bfs() {
	queue<pair<int, int>> q;
	queue<pair<int, int>> door[26];
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!InRange(nx, ny) || grid[nx][ny] == '*' || visited[nx][ny]) continue;

			visited[nx][ny] = true;

			char next = grid[nx][ny];

			if (next >= 'A' && next <= 'Z') {
				if (keyArr[next - 'A']) q.push({nx, ny});
				else door[next - 'A'].push({ nx, ny });
			}
			else if (next >= 'a' && next <= 'z') {
				q.push({ nx, ny });
				if (!keyArr[next - 'a']) { 
					keyArr[next - 'a'] = true;

					while (!door[next - 'a'].empty()) {
						q.push(door[next - 'a'].front());
						door[next - 'a'].pop();
					}
				}
			}
			else {
				q.push({ nx, ny });
				if (next == '$') answer++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		Initialize();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			for (int j = 1; j <= m; j++) {
				grid[i][j] = str[j-1];
			}
		}

		string key;
		cin >> key;
		if (key != "0") {
			for (int i = 0; i < key.length(); i++) {
				keyArr[key[i] - 'a'] = true;
			}
		}

		bfs();

		cout << answer << "\n";
	}

	return 0;
}