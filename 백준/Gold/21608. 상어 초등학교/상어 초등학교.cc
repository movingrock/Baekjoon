#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> student;
vector<int> like[401];
int grid[21][21] = { 0, };
int n, num, like_num;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int answer = 0;

bool InRange(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void findSeat(int st) {
	int friend_num = INT_MIN;
	int empty_num = INT_MIN;
	pair<int, int> canSeat; // 앉을 수 있는 자리 후보

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 친구 찾기
			if (grid[i][j] != 0) continue;
			int x = i;
			int y = j;
			int cnt = 0;
			int empty_cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (InRange(nx, ny)) {
					for (int l = 0; l < 4; l++) {
						if (like[st][l] == grid[nx][ny]) cnt++;
					}
					if (grid[nx][ny] == 0) empty_cnt++;
				}
			}

			if (cnt > friend_num) {
				friend_num = cnt;
				empty_num = empty_cnt;
				canSeat = { i, j };
			}
			else if (cnt == friend_num) {
				if (empty_cnt > empty_num) {
					empty_num = empty_cnt;
					canSeat = { i, j };
				}
			}
		}
	}

	grid[canSeat.first][canSeat.second] = st;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> num;
		student.push_back(num);
		for (int j = 0; j < 4; j++) {
			cin >> like_num;
			like[num].push_back(like_num);
		}
	}

	for (int i = 0; i < n * n; i++) {
		findSeat(student[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int st = grid[i][j];
			int x = i;
			int y = j;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (!InRange(nx, ny)) continue;
				for (int l = 0; l < 4; l++) {
					if (like[st][l] == grid[nx][ny]) cnt++;
				}
			}
			if (cnt == 4) answer += 1000;
			else if (cnt == 3) answer += 100;
			else if (cnt == 2) answer += 10;
			else if (cnt == 1) answer += 1;
		}
	}

	cout << answer;

	return 0;
}