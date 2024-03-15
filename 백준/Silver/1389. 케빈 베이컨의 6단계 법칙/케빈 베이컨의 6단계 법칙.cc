#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>

#define MAXN 101

using namespace std;

int n, m;
vector<int> v[MAXN];

int dist[MAXN][MAXN] = { 0, };
int sum[MAXN] = { 0, };

void bfs(int start) {
	int visited[MAXN] = { 0, };
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				dist[start][y] = dist[start][x] + 1;
			}

		}

	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int min_sum = INT_MAX;
	int min_person = 0;

	for (int i = n; i >= 1; i--) {
		bfs(i);
		for (int j = 1; j <= n; j++) {
			sum[i] += dist[i][j];
		}
		min_sum = min(min_sum, sum[i]);
		if (min_sum == sum[i]) min_person = i;
	}

	cout << min_person;

	return 0;
}