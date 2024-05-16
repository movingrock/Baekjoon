#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int grid[101][101] = { 0, };
vector<pair<int, char>> v;
int n;
int dir = 0; // 오른쪽
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

deque<pair<int, int>> dq;
bool finished = false;
int answer = 0;

bool InRange(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool MyBody(int x, int y) {
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i].first == x && dq[i].second == y) return true;
	}
	return false;
}

void Move() {
	int headX = dq.front().first;
	int headY = dq.front().second;

	int nx = headX + dx[dir];
	int ny = headY + dy[dir];

	if (!InRange(nx, ny)) { 
		finished = true; return; 
	}
	else if (MyBody(nx, ny)) {
		finished = true; return;
	}
	else if (grid[nx][ny] == 9) {
		dq.push_front({ nx, ny });
		grid[nx][ny] = 0;
	}
	else if (grid[nx][ny] == 0) {
		dq.push_front({ nx, ny });
		dq.pop_back();
	}
	answer++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		grid[a][b] = 9;
	}

	int l;
	cin >> l;

	dq.push_back({ 1, 1 });

	for (int i = 0; i < l; i++) {
		int x; char c;
		cin >> x >> c;
		v.push_back({ x, c });
	}

	int cnt = 0;
	while (true) {
		Move();
		if (finished) break;
		if (cnt < v.size() && v[cnt].first == answer) {
			if (v[cnt].second == 'D')dir = (dir + 1) % 4;
			else if (v[cnt].second == 'L')dir = (dir + 3) % 4;
			cnt++;
		}
	}

	cout << answer + 1;

	return 0;
}