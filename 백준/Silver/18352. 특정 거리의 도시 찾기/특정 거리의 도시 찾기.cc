#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

#define MAX 300001
#define INF 987654321

using namespace std;

int n, m, k, x;

int dist[MAX];
vector<int> v[MAX];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, x});
	dist[x] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			
			if (dist[next] > cost + 1) {
				dist[next] = cost + 1;
				pq.push({ cost + 1, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dijkstra();

	bool noRoute = true;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			noRoute = false;
			cout << i << "\n";
		}
	}

	if (noRoute) cout << -1;

	return 0;
}