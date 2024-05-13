#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int grid[21][21];
bool check[21];


int answer = INT_MAX;
int n;

void Score() {
	int teamA = 0;
	int teamB = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (check[i] && check[j]) {
				teamA += grid[i][j] + grid[j][i];
			}
			else if(!check[i] && !check[j]) {
				teamB += grid[i][j] + grid[j][i];
			}
		}
	}
	answer = min(answer, abs(teamA - teamB));
}

// 절반 선택
void Func(int cnt, int index) {
	if (cnt == n/2) {
		Score();
		return;
	}

	for (int i = index; i <= n; i++) {
		if (!check[i]) {
			check[i] = true;
			Func(cnt + 1, i);
			check[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	Func(0, 1);

	cout << answer;

	return 0;
}
