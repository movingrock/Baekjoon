#include <iostream>

using namespace std;

int grid[2][100001];
int dp[2][100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        dp[0][0] = grid[0][0];
        dp[1][0] = grid[1][0];
        dp[0][1] = grid[1][0] + grid[0][1];
        dp[1][1] = grid[0][0] + grid[1][1];


        for (int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + grid[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + grid[1][i];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }

    return 0;
}