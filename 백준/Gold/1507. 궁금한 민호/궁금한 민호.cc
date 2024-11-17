#include <iostream>

#define MAX 21 

using namespace std;

int grid[MAX][MAX];
bool route[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (grid[i][k] + grid[k][j] < grid[i][j]) {
					cout << "-1";
					return 0;
				}
				if (i != k && j != k && grid[i][k] + grid[k][j] == grid[i][j]) {
					route[i][j] = true;
				}
			}
		}
	}

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!route[i][j]) answer += grid[i][j];
		}
	}

	cout << answer / 2;


	return 0;
}