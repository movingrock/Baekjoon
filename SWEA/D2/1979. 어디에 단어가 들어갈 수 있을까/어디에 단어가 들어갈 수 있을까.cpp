#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		int ans = 0;
		int grid[15][15];

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) continue;

				if ((i == 0 && grid[i + 1][j] == 1) || (i != 0 && grid[i - 1][j] == 0)) {
					int cnt = 1;
					for (int k = i + 1; k < n; k++) {
						if (grid[k][j] == 0) break;
						cnt++;
					}
					if (cnt == k) ans++;
				}

				if ((j == 0 && grid[i][j + 1]) || (j != 0 && grid[i][j - 1] == 0)) {
					int cnt = 1;

					for (int k = j + 1; k < n; k++) {
						if (grid[i][k] == 0) break;
						cnt++;
					}
					if (cnt == k) ans++;

				}

			}
		}


		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}