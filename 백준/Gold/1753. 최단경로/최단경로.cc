#include <iostream>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

vector<pair<int, int>> graph[20001]; // 도착지점, 거리
int dist[20001];

void bfs(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start)); // 노드, 거리합
	
	while (!pq.empty()) {
		int x = pq.top().second;
		int cnt = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i].first;
			int nCnt = graph[x][i].second;

			if (dist[y] > cnt + nCnt) {
				dist[y] = cnt + nCnt;
				pq.push(make_pair(cnt + nCnt, y));
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int v, e, k;
	cin >> v >> e >> k;
	int u, vv, w;
	for (int i = 0; i < e; i++) {
		cin >> u >> vv >> w;
		graph[u].push_back(make_pair(vv, w));
	}

	for (int i = 1; i <= v; i++) {
		dist[i] = INF;
	}

	bfs(k);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}