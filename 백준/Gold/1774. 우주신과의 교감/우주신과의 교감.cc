#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<double, pair<int, int>>> graph;
vector<pair<int, int>> pos;
vector<pair<int, int>> already;

int parent[1001];


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

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pos.push_back({ a, b });
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		already.push_back({ a, b });
	}

	// parent 배열 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	// 이미 이어진 노드 처리
	for (int i = 0; i < m; i++) {
		int x = already[i].first;
		int y = already[i].second;

		if (!SameParent(x, y)) Union(x, y);
	}

	// 각 노드간 거리계산
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			graph.push_back({ dist, {i + 1, j + 1} });
		}
	}

	// 가중치 오름차순으로 정렬
	sort(graph.begin(), graph.end());

	double answer = 0;

	// 가중치가 가장 작은것부터 탐색
	// 부모가 다르면 하나의 집합으로 묶고,
	// 가중치의 값을 더함.
	// (부모가 같을때는 사이클이 생기는 경우이기에 제외한다)
	for (int i = 0; i < graph.size(); i++) {
		if (!SameParent(graph[i].second.first, graph[i].second.second)) {
			Union(graph[i].second.first, graph[i].second.second);
			answer += graph[i].first;
		}
	}
	cout << fixed;
	cout.precision(2);

	cout << answer;

	return 0;
}