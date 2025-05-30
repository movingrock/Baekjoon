#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> graph;

int parent[10001];

// Union-Find

// 재귀로 부모노드 찾아서 반환
int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

// 하나의 부모로 묶는 함수 (SameParent가 true일때 사용)
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}

// 두 노드의 부모가 같으면 true, 아니면 false
bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c, {a, b} });
	}

	// 가중치 오름차순으로 정렬
	sort(graph.begin(), graph.end());

	// parent 배열 초기화
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	int answer = 0;

	// 가중치가 가장 작은것부터 탐색
	// 부모가 다르면 하나의 집합으로 묶고,
	// 가중치의 값을 더함.
	// (부모가 같을때는 사이클이 생기는 경우이기에 제외한다)
	for (int i = 0; i < e; i++) {
		if (!SameParent(graph[i].second.first, graph[i].second.second)) {
			Union(graph[i].second.first, graph[i].second.second);
			answer += graph[i].first;
		}
	}

	cout << answer;

	return 0;
}
