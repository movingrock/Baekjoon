#include <iostream>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	long long b;
	cin >> n >> m >> b;
	int grid[500][500];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = INT_MAX;
	int height = 0;
	for (int i = 0; i <= 256; i++) {
		int remove = 0;
		int build = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (grid[j][k] > i) {
					remove += (grid[j][k] - i);
				}
				else if (grid[j][k] < i) {
					build += (i - grid[j][k]);
				}
			}
		}

		if (b + remove >= build) {
			int time = remove * 2 + build;
			ans = min(ans, time);
			if (ans == time) height = i;
		}
	}

	cout << ans << " " << height;

	return 0;
}