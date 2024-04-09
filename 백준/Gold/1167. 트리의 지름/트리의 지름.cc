#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v[100001];
bool visited[100001];
int max_node;
int max_dist = 0;

void dfs(int n, int cnt) {
	if (visited[n]) return;

	if (max_dist < cnt) {
		max_node = n;
		max_dist = cnt;
	}

	visited[n] = true;

	for (int i = 0; i < v[n].size(); i++) {
		int node = v[n][i].first;
		int cur_cnt = v[n][i].second;
		dfs(node, cnt + cur_cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		int n1, n2;
		while (true) {
			cin >> n1;
			if (n1 == -1) break;
			cin >> n2;
			v[num].push_back(make_pair(n1, n2));
			v[n1].push_back(make_pair(num, n2));
		}
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
	dfs(max_node, 0);
	cout << max_dist;
	return 0;
}