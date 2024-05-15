#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

#define INF 99999999

using namespace std;

int n;
int grid[100][100] = { 0, };
int cost[100][100] = { 0, };

int dx[4] = { 0, 1, 0, -1 }; // 순서 바꿔야될수 있음
int dy[4] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 0 });
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (InRange(nx, ny)) {
				int nCnt = cnt + grid[nx][ny];
				if (cost[nx][ny] > nCnt) {
					cost[nx][ny] = nCnt;
					q.push({ {nx, ny}, nCnt });
				}

			}
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
		cin >> n;
		for (int i = 0; i < n; i++) {
			string num; cin >> num;
			for (int j = 0; j < n; j++) {
				grid[i][j] = (num[j] - '0');
				cost[i][j] = INF;
			}
		}

		bfs();

		cout << "#" << test_case << " " << cost[n-1][n-1] << endl;

	}
	return 0;
}