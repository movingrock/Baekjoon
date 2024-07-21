#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	vector<int> answer(n+m);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int pa = 0;
	int pb = 0;
	int index = 0;

	while (pa < n && pb < m) {
		if (a[pa] < b[pb]) answer[index++] = a[pa++];
		else answer[index++] = b[pb++];
	}

	while (pa < n) answer[index++] = a[pa++];
	while (pb < m) answer[index++] = b[pb++];

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}