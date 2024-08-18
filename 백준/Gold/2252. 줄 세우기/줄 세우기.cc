#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[32001];
int inDegree[32001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (!inDegree[i]) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++) {
			inDegree[graph[cur][i]]--;
			if (!inDegree[graph[cur][i]])
				q.push(graph[cur][i]);
		}
	}

	return 0;
}