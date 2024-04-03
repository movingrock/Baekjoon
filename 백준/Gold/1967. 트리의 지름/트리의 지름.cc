#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v[10001];
bool visited[10001] = { 0, };
int ans = 0;
int first_point = 0;

void dfs(int x, int cnt) {
	if (visited[x]) return;

	visited[x] = true;
	if (ans < cnt) {
		ans = cnt;
		first_point = x;
	}

	for (int i = 0; i < v[x].size(); i++) {
		dfs(v[x][i].first, v[x][i].second + cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}

	dfs(first_point, 0);
	cout << ans;

	return 0;
}