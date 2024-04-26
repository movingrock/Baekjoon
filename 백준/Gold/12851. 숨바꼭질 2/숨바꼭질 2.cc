#include <iostream>
#include <climits>
#include <queue>
using namespace std;

int min_time = INT_MAX;
int plan = 1;
int n, k;
bool visited[100001] = { 0, };

bool InRange(int x) {
	return x >= 0 && x <= 100000;
}

void bfs() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, n });
	
	int prev = INT_MAX;
	while (!q.empty()) {
		int cnt = q.top().first;
		int x = q.top().second;
		q.pop();
		visited[x] = true;

		if (x == k) {
			if (min_time > cnt) {
				min_time = cnt;
				plan = 1;
			}
			else if (min_time == cnt) {
				plan++;
			}
		}

		if (cnt > min_time) continue;

		if (InRange(x + 1) && !visited[x + 1]) q.push({ cnt + 1, x + 1 });
		if (InRange(x - 1) && !visited[x - 1]) q.push({ cnt + 1, x - 1 });
		if (InRange(x * 2) && !visited[x * 2]) q.push({ cnt + 1, x * 2 });
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	bfs();

	cout << min_time << "\n" << plan;

	return 0;
}