#include<iostream>
#include <cstring>
using namespace std;

int n, k;
bool visited[21];
int arr[20];
int answer = 0;

void backtracking(int cnt, int sum) {
	if (sum == k) answer++;
	if (cnt == n) return;
	for (int i = cnt; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			backtracking(i, sum + arr[i]);
			visited[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(visited, false, sizeof(visited));
		answer = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		backtracking(0, 0);

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}