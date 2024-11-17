#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, pair<int, int>>> graph;
vector<pair<int, int>> pos;
vector<pair<int, int>> already;

int parent[1001];

char university[1001];

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

	for (int i = 1; i <= n; i++) {
		cin >> university[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({ c, {a, b} });
	}

	// parent 배열 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	// 가중치 오름차순으로 정렬
	sort(graph.begin(), graph.end());

	int answer = 0;

	// 가중치가 가장 작은것부터 탐색
	// 부모가 다르면 하나의 집합으로 묶고,
	// 가중치의 값을 더함.
	// (부모가 같을때는 사이클이 생기는 경우이기에 제외한다)
	for (int i = 0; i < graph.size(); i++) {
		int x = graph[i].second.first;
		int y = graph[i].second.second;
		if (!SameParent(x, y) && university[x] != university[y]) {
			Union(x, y);
			answer += graph[i].first;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (Find(i) != Find(1)) {
			cout << "-1";
			return 0;
		}
	}

	cout << answer;

	return 0;
}