#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > 0) pq.push(num);
		else if (num == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}

	return 0;
}