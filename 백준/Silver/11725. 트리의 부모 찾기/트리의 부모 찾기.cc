#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100001];
int arr[100001];
bool visited[100001];

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int x = q.front();
		visited[x] = true;
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!visited[y]) {
				arr[y] = x;
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= n; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}