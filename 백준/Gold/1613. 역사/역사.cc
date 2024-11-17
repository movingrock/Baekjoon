#include <iostream>

#define MAX 401 

using namespace std;

int grid[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k, s;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		grid[a][b] = -1;
		grid[b][a] = 1;
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (grid[i][j] == 0) {
					if (grid[i][k] == 1 && grid[k][j] == 1) grid[i][j] = 1;
					else if (grid[i][k] == -1 && grid[k][j] == -1) grid[i][j] = -1;
				}
			}
		}
	}

	cin >> s;

	while (s--) {
		int a, b;
		cin >> a >> b;
		cout << grid[a][b] << "\n";
	}

	return 0;
}