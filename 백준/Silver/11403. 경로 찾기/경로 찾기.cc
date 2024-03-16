#include <iostream>
#include <queue>

using namespace std;

int n;
int grid[101][101] = { 0, };

void bfs(int start) {
	queue<int> q;
	q.push(start);
	bool visited[101] = { 0, };
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (grid[x][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
				grid[start][i] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}