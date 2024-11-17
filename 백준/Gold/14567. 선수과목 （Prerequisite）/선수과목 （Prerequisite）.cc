#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 1001

using namespace std;

int inDegree[MAX];
int answer[MAX];
vector<int> graph[MAX];


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
		answer[i] = 1;
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			inDegree[next]--;
			if (!inDegree[next]) {
				q.push(next);
				answer[next] = max(answer[next], answer[cur] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}