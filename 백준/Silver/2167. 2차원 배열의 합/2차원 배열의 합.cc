#include <iostream>

#define MAX 301

using namespace std;

int grid[MAX][MAX];
int prefixSum[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> prefixSum[i][j];
			prefixSum[i][j] += prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1];
		}
	}

	int k;
	cin >> k;
	while (k--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << prefixSum[x][y] - prefixSum[i - 1][y] - prefixSum[x][j - 1] + prefixSum[i - 1][j - 1] << "\n";
	}

	return 0;
}