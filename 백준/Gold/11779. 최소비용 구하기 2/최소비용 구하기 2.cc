#include <iostream>
#include <queue>
#include <vector>

#define INF 2000000000

using namespace std;

vector<pair<int, int>> v[1001];

int n, m;
int s, e;

int dist[1001];
int beforeNode[1001];

void bfs() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cnt > dist[node]) continue;

		for (int i = 0; i < v[node].size(); i++) {
			int nNode = v[node][i].first;
			int nCnt = v[node][i].second;

			if (dist[nNode] > cnt + nCnt) {
				dist[nNode] = cnt + nCnt;
				pq.push({ cnt + nCnt, nNode });
				beforeNode[nNode] = node;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	cin >> s >> e;

	bfs();

	vector<int> ans;
	ans.push_back(e);
	int before = beforeNode[e];
	while (before) {
		ans.push_back(before);
		before = beforeNode[before];
	}

	cout << dist[e] << "\n" << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}

	return 0;
}