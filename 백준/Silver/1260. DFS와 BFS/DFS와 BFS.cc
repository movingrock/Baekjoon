#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> graph[1001];

bool visited1[1001] = { 0, };
bool visited2[1001] = { 0, };

void dfs(int x) {
	cout << x << " ";
	visited1[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited1[y]) dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited2[start] = true;

	while (!q.empty()) {
		int x = q.front();
		cout << x << " ";
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited2[y]) { 
				q.push(y); 
				visited2[y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}