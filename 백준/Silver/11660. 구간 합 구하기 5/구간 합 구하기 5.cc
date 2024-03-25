#include <iostream>

using namespace std;

int grid[1025][1025];
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) dp[i][j] = grid[i][j];
            else if (j == 1) dp[i][j] = dp[i - 1][n] + grid[i][j];
            else dp[i][j] = dp[i][j - 1] + grid[i][j];
        }
    }

    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int i = x1; i <= x2; i++) {
            if (y1 == 1 && i == 1) sum += (dp[i][y2]);
            else if (y1 == 1) sum += (dp[i][y2] - dp[i - 1][n]);
            else sum += (dp[i][y2] - dp[i][y1 - 1]);
        }

        cout << sum << "\n";
    }

    return 0;
}