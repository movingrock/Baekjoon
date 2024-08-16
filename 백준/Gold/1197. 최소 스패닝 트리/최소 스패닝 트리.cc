#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];

int answer = 0;

int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y] = x;
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E;
	cin >> V >> E;

	vector<pair<int, pair<int, int>>> v;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	int answer = 0;

	for (int i = 0; i < v.size(); i++) {
		if (!sameparent(v[i].second.first, v[i].second.second)) {
			uni(v[i].second.first, v[i].second.second);
			answer += v[i].first;
		}
	}

	cout << answer;


	return 0;
}