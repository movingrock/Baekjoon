#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int cnt = 0;

		// queue에 push
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			q.push(make_pair(num, j));
			pq.push(num);
		}

		while (!q.empty()) {
			int value = q.front().first;
			int order = q.front().second;
			q.pop();

			if (pq.top() == value) {
				pq.pop();
				cnt++;
				if (order == m) {
					cout << cnt << "\n";
				}
			}
			else {
				q.push(make_pair(value, order));
			}
		}
	}
	return 0;
}