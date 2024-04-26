#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int grid[21][21];
bool visited[21][21]; // 초기화 해야함

int sharkX, sharkY;
int shark_size = 2;
int eat_fish = 0;
int min_fish;
int min_cnt;
int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool finished = false;
int ans = 0;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

// 만약에 priority queue에 작은 크기대로 물고기랑, x, y좌표값을 넣어준다면?

void initialize() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

void findFish(int x, int y) { // 상어의 위치
	initialize();
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x, y}, 0 });
	visited[x][y] = true;
	min_fish = INT_MAX;
	min_cnt = INT_MAX;

	int prev_sharkX = sharkX;
	int prev_sharkY = sharkY;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		// 제일 작은 물고기를 먹는게 아님. 내 크기보다 작으면 먹을 수 있음.
		// 그 중에서 가까운거, 여러개라면 위쪽 우선 왼쪽 차선
		if (grid[x][y] != 0 && shark_size > grid[x][y]) {
			if (min_cnt > cnt) {
				min_cnt = cnt;
				sharkX = x;
				sharkY = y;
			}
			else if (min_cnt == cnt) {
				if (x < sharkX) {
					sharkX = x;
					sharkY = y;
				}
				else if (x == sharkX && y < sharkY) {
					sharkX = x;
					sharkY = y;
				}

			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (InRange(nx, ny) && !visited[nx][ny] && shark_size >= grid[nx][ny]) {
				q.push({ {nx, ny}, cnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}

	// 위치가 안바뀌었으면 끝난거
	if (prev_sharkX == sharkX && prev_sharkY == sharkY) {
		finished = true;
	}
	else { // 물고기를 먹었으면 움직인 만큼 값을 더하고, 물고기 먹은 양도 더하고, 상어가 도착한 곳을 0으로 표시
		ans += min_cnt;
		eat_fish++;
		grid[sharkX][sharkY] = 0;
	}

	// 물고기 성장
	if (eat_fish == shark_size) {
		shark_size++;
		eat_fish = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 9) {
				sharkX = i;
				sharkY = j;
				grid[i][j] = 0;
			}
		}
	}

	while (!finished) {
		findFish(sharkX, sharkY);
	}

	cout << ans;

	return 0;
}