#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	queue<int> answer;

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		int y = q.front();
		answer.push(y);
		q.pop();
	}

	cout << "<";
	while(!answer.empty()) {
		cout << answer.front();
		answer.pop();
		if (!answer.empty()) cout << ", ";
	}
	cout << ">";

	return 0;
}