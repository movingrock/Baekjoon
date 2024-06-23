#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[1000001] = { 0 , };
int score[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		visited[v[i]] = true;
	}

	for (int i = 0; i < n; i++) {
		for (int j = v[i] * 2; j < 1000001; j += v[i]) {
			if (visited[j]) {
				score[v[i]]++;
				score[j]--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << score[v[i]] << " ";
	}

	return 0;
}