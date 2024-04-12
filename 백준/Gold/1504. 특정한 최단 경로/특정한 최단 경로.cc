#include <iostream>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

vector<pair<int, int>> v[801];
int dist[801];

void Dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0, start)); // dist , node
	dist[start] = 0;

	while (!pq.empty()) {
		int cnt = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i].first;
			int nCnt = v[node][i].second;

			if (dist[next] > cnt + nCnt) {
				dist[next] = cnt + nCnt;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, e;
	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	int r1 = 0; // 1 -> v1 -> v2 -> n
	int r2 = 0; // 1 -> v2 -> v2 -> n
	bool isr1 = true;
	bool isr2 = true;


	for (int i = 1; i <= n; i++) dist[i] = INF;
	Dijkstra(1);
	if (dist[v1] == INF) isr1 = false;
	if (dist[v2] == INF) isr2 = false;
	if (dist[n] == INF) { isr1 = false; isr2 = false; }
	if(isr1) r1 += dist[v1]; 
	if(isr2) r2 += dist[v2];

	for (int i = 1; i <= n; i++) dist[i] = INF;
	Dijkstra(v1);
	if (isr1) r1 += dist[v2];
	if (isr2) r2 += dist[v2];

	for (int i = 1; i <= n; i++) dist[i] = INF;
	Dijkstra(v2);
	if (isr1) r1 += dist[n];

	for (int i = 1; i <= n; i++) dist[i] = INF;
	Dijkstra(v1);
	if (isr2) r2 += dist[n];
	
	if (!isr1 && !isr2) cout << -1;
	else cout << min(r1, r2);

	return 0;
}