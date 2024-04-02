#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

bool InRange(int x) {
	return x >= 0 && x <= 100000;
}

void bfs(int n, int k) {
	deque<pair<int, int>> q; // 1 위치 2 cnt
	q.push_back(make_pair(n, 0));
	visited[n] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop_front();

		if (x == k) { cout << cnt; return; }

		int nx1 = x + 1;
		int nx2 = x - 1;
		int nx3 = 2 * x;
		if (InRange(nx3) && !visited[nx3]) {
			q.push_front(make_pair(nx3, cnt));
			visited[nx3] = true;
		}
		if (InRange(nx2) && !visited[nx2]) {
			q.push_back(make_pair(nx2, cnt + 1));
			visited[nx2] = true;
		}
		if (InRange(nx1) && !visited[nx1]) {
			q.push_back(make_pair(nx1, cnt + 1));
			visited[nx1] = true;
		}

	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	bfs(n, k);

	return 0;
}