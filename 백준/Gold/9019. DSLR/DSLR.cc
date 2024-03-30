#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

bool visited[10001] = { 0, };
int a, b;

void bfs() {
	queue<pair<int, string>> q;
	string command = "";
	q.push(make_pair(a, command));

	while (!q.empty()) {
		int s_first = q.front().first;
		string s_second = q.front().second;
		q.pop();

		if (s_first == b) {
			cout << s_second << "\n";
			break;
		}

		int d = (s_first * 2) % 10000;
		if (!visited[d]) {
			visited[d] = true;
			q.push(make_pair(d, s_second + "D"));
		}

		int s = s_first == 0 ? 9999 : s_first - 1;
		if (!visited[s]) {
			visited[s] = true;
			q.push(make_pair(s, s_second + "S"));
		}

		int l = (s_first % 1000) * 10 + (s_first / 1000);
		if (!visited[l]) {
			visited[l] = true;
			q.push(make_pair(l, s_second + "L"));
		}

		int r = (s_first / 10) + (s_first % 10) * 1000;
		if (!visited[r]) {
			visited[r] = true;
			q.push(make_pair(r, s_second + "R"));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		bfs();
	}

	return 0;
}