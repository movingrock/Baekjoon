#include <iostream>
#include <vector>
#include <cstring>

#define NUM 100001
using namespace std;

int arr[NUM];
bool visited[NUM];
bool finished[NUM];
int answer = 0;

void dfs(int n) {
	visited[n] = true;
	if (!visited[arr[n]]) {
		dfs(arr[n]);
	}
	else if (!finished[arr[n]]) {
		answer++;
		for (int i = arr[n]; i != n; i = arr[i]) {
			answer++;
		}
	}
	finished[n] = true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			if(!visited[i])	dfs(i);
		}

		cout << n - answer << "\n";

		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		answer = 0;

	}

	return 0;
}