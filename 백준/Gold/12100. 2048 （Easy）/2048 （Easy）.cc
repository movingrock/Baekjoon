#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;
int n;

vector<vector<int>> MoveR(vector<vector<int>> v) {
	for (int i = 0; i < n; i++) {
		queue<int> q;
		for (int j = n-1; j >= 0; j--) {
			if (v[i][j] == 0) continue;

			q.push(v[i][j]);
			v[i][j] = 0;
		}

		int index = n-1;
		while (!q.empty()) {
			int first = q.front();
			q.pop();

			if (q.size() == 0) {
				v[i][index] = first;
				break;
			}
			else if (first != q.front()) {
				v[i][index] = first;
				index--;
			}
			else if (first == q.front()) {
				v[i][index] = first * 2;
				q.pop();
				index--;
			}
		}
	}
	return v;
}

vector<vector<int>> MoveL(vector<vector<int>> v) {
	for (int i = 0; i < n; i++) {
		queue<int> q;
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 0) continue;
			
			q.push(v[i][j]);
			v[i][j] = 0;
		}

		int index = 0;
		while (!q.empty()) {
			int first = q.front();
			q.pop();

			if (q.size() == 0) {
				v[i][index] = first;
				break;
			}
			else if (first != q.front()) {
				v[i][index] = first;
				index++;
			}
			else if (first == q.front()) {
				v[i][index] = first * 2;
				q.pop();
				index++;
			}
		}
	}
	return v;
}

vector<vector<int>> MoveU(vector<vector<int>> v) {
	for (int i = 0; i < n; i++) {
		queue<int> q;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 0) continue;

			q.push(v[j][i]);
			v[j][i] = 0;
		}

		int index = 0;
		while (!q.empty()) {
			int first = q.front();
			q.pop();

			if (q.size() == 0) {
				v[index][i] = first;
				break;
			}
			else if (first != q.front()) {
				v[index][i] = first;
				index++;
			}
			else if (first == q.front()) {
				v[index][i] = first * 2;
				q.pop();
				index++;
			}
		}
	}
	return v;
}

vector<vector<int>> MoveD(vector<vector<int>> v) {
	for (int i = 0; i < n; i++) {
		queue<int> q;
		for (int j = n-1; j >= 0; j--) {
			if (v[j][i] == 0) continue;

			q.push(v[j][i]);
			v[j][i] = 0;
		}

		int index = n-1;
		while (!q.empty()) {
			int first = q.front();
			q.pop();

			if (q.size() == 0) {
				v[index][i] = first;
				break;
			}
			else if (first != q.front()) {
				v[index][i] = first;
				index--;
			}
			else if (first == q.front()) {
				v[index][i] = first * 2;
				q.pop();
				index--;
			}
		}
	}
	return v;
}

int FindMax(vector<vector<int>> v) {
	int max_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_ans = max(max_ans, v[i][j]);
		}
	}
	return max_ans;
}

void Backtracking(int cnt, vector<vector<int>> v) {
	if (cnt == 5) {
		answer = max(answer, FindMax(v));
		return;
	}

	Backtracking(cnt + 1, MoveR(v));
	Backtracking(cnt + 1, MoveL(v));
	Backtracking(cnt + 1, MoveU(v));
	Backtracking(cnt + 1, MoveD(v));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		vector<int> v1;
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			v1.push_back(num);
		}
		v.push_back(v1);
	}

	Backtracking(0, v);

	cout << answer;

	return 0;
}