#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> jewerly[300001];
int bag[300001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	long long answer = 0;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		cin >> jewerly[i].first >> jewerly[i].second;
	}

	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}

	sort(jewerly, jewerly + n);
	sort(bag, bag + k);

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		while (cnt < n && bag[i] >= jewerly[cnt].first) {
			pq.push(jewerly[cnt].second);
			cnt++;
		}

		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;


	return 0;
}