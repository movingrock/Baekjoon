#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, pair<int, int>>> graph;

int parent[100001];

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

	long long sum = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		graph.push_back({ c, {a, b} });
		sum += c;
	}

	// 가중치 오름차순으로 정렬
	sort(graph.begin(), graph.end());

	// parent 배열 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	long long answer = 0;

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


	// 1번 노드의 부모와 다른 노드의 부모가 다르면 이어져있지 않다.
	for (int i = 2; i <= n; i++) {
		if (Find(i) != Find(1)) {
			cout << "-1";
			return 0;
		}
	}
	cout << sum - answer;

	return 0;
}