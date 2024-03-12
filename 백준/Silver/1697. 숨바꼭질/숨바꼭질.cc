#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
bool visited[100001] = { 0, };
int n, k;

bool InRagne(int x) {
	return x >= 0 && x <= 100000;
}

void bfs() {
	while (!q.empty()) {
		if (q.front().first == k) {
			cout << q.front().second;
			return;
		}

		int x = q.front().first;
		int t = q.front().second;
		visited[x] = true;
		q.pop();
	

		if (InRagne(x-1) && !visited[x - 1]) {
			q.push(make_pair(x - 1, t + 1));
		}
		if (InRagne(x + 1) && !visited[x + 1]) {
			q.push(make_pair(x + 1, t + 1));
		}
		if (InRagne(2 * x) && !visited[2 * x]) {
			q.push(make_pair(2 * x, t + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	q.push(make_pair(n, 0));

	bfs();

	return 0;
}