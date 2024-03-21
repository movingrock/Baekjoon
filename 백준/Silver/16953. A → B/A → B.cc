#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int n, m;
int ans = -1;

void bfs() {
	queue<pair<long long, int>> q;
	q.push(make_pair(n, 0));

	while (!q.empty()) {
		long long x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == m) { ans = cnt + 1; return; }

		if (x * 2 <= m) q.push(make_pair(2 * x, cnt + 1));
		if (10 * x + 1 <= m)q.push(make_pair(10 * x + 1, cnt + 1));
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	bfs();

	cout << ans;

	return 0;
}