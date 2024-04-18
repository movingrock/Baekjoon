#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v[101];
bool visited[101];
int t[101];
int n, m, r;

void bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < v[node].size(); i++) {
			int nNode = v[node][i].first;
			int nCnt = v[node][i].second;
			if (cnt + nCnt <= m) {
				q.push({ nNode, cnt + nCnt });
				visited[nNode] = true;
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			visited[j] = false;
		}
		bfs(i);
		for (int j = 1; j <= n; j++) {
			if (visited[j]) sum += t[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;

	return 0;
}
