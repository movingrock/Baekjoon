#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[32001];
int inDegree[32001];
int sum[1001];
int arr[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, w;
		cin >> n >> k;
		int answer = 0;

		for (int i = 1; i <= n; i++) {
			graph[i].clear();
			inDegree[i] = 0;
			sum[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			inDegree[b]++;
		}

		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!inDegree[i]) q.push(i);
			sum[i] = arr[i];
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i];
				sum[next] = max(sum[next], sum[cur] + arr[next]);

				inDegree[next]--;
				if (!inDegree[next]) {
					q.push(next);
				}
			}
		}


		cout << sum[w] << "\n";
	}

	return 0;
}