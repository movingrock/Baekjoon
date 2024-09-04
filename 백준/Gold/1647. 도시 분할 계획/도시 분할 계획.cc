#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int a, b, c;

vector<pair<int, pair<int, int>>> graph;
int parent[100001];
vector<int> v;

int Find_Parent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = Find_Parent(parent[x]);
}

void Union(int x, int y, int cost) {
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x == y) return;
	parent[y] = x;
	n--;
}

bool Same_Parent(int x, int y) {
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x == y) return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph.push_back({ c, {a, b} });
	}

	sort(graph.begin(), graph.end());
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < graph.size(); i++) {
		if (!Same_Parent(graph[i].second.first, graph[i].second.second)) {
			Union(graph[i].second.first, graph[i].second.second, graph[i].first);
			v.push_back(graph[i].first);
		}
	}

	int answer = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		answer += v[i];
	}
	cout << answer;
	return 0;
}