#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	//vector<int> a(n);
	//vector<int> b(m);
	vector<int> answer(n + m);
	for (int i = 0; i < n + m; i++) {
		cin >> answer[i];
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < n + m; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}