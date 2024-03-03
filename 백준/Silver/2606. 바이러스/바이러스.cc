#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101];
bool check[101];
int cnt = 0;

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int linked = v[x][i];
		if (!check[linked]) {
			dfs(linked);
			cnt++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << cnt;
	return 0;
}