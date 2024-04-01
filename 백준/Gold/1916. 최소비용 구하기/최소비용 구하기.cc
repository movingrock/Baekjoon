#include <iostream>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int>> grid[1001];
int dist[1001];

void bfs(int start) {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		int node = pq.top().first;
		int cnt = pq.top().second;
		pq.pop();

		if (dist[node] < cnt) continue;

		for (int i = 0; i < grid[node].size(); i++) {
			int nNode = grid[node][i].first;
			int nCnt = grid[node][i].second + cnt;

			if (dist[nNode] > nCnt) {
				pq.push({ nNode, nCnt });
				dist[nNode] = nCnt;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		grid[a].push_back({ b, c });
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}

	bfs(start);

	cout << dist[end];

	return 0;
}