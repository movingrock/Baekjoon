#include <iostream>
#include <queue>
using namespace std;

int arr[101];
bool visited[101] = { 0, };
void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx == 100) { cout << cnt + 1;  return; }
			else if (nx < 100) {
				while (arr[nx] != 0) nx = arr[nx];
				
				if (!visited[nx]) {
					visited[nx] = true;
					q.push(make_pair(nx, cnt + 1));
				}
			}
		}

	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	bfs();

	// 버튼을 거의 자리수에 맞춰서 눌러줌.
	// 그 수랑 뺀값이랑 더해줌.

	return 0;
}