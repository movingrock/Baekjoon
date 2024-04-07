#include <iostream>
#include <queue>
#include <cstring>

#define INF 99999999

using namespace std;

int n, m, x;
int grid[1001][1001];
int dist[1001];
int min_dist = 0;

void bfs(int start, int end) {
	fill(dist, dist + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int cnt = pq.top().first;
		int node = pq.top().second;

		if (node == end) {
			min_dist = dist[end];
			return;
		}

		pq.pop();

		for (int i = 1; i <= n; i++) {
			if (node == i || grid[node][i] == INF) continue;
			int nCnt = grid[node][i] + cnt;
			if(dist[i] > nCnt){
				dist[i] = nCnt;
				pq.push(make_pair(dist[i], i));

			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b, t;
	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		for (int j = 1; j <= n; j++) {
			grid[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		grid[a][b] = t;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		int a, b;
		bfs(i, x); a = min_dist;
		bfs(x, i); b = min_dist;
		ans = max(ans, a + b);
	}

	cout << ans;

	return 0;
}