#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[32001];
int inDegree[32001];
int n, m;

void topology() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			inDegree[next]--;
			if (!inDegree[next]) pq.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}

	topology();

	return 0;
}