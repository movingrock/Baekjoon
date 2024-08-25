#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

vector<vector<int>> graph(1001);
int inDegree[1001];

int arr[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x == 0 || x == 1) continue;
		for (int j = 0; j < x; j++) {
			cin >> arr[j];
		}
		for (int j = 0; j < x - 1; j++) {
			graph[arr[j]].push_back(arr[j + 1]);
			inDegree[arr[j+1]]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i]) q.push(i);
	}

	vector<int> answer;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		answer.push_back(cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			inDegree[next]--;
			if (!inDegree[next]) q.push(next);
		}
	}

	if (answer.size() != n) cout << 0;
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
	}

	return 0;
}