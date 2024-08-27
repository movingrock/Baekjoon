#include <iostream>

#define MOD 1000000000;

using namespace std;

int dp[101][10][1 << 10]; // dp[i][j][k] 길이가 i 이면서, 마지막 자리가 j일때의, 0~9가 포함되어있는지를 확인 할 수 있는 비트값 k.

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) dp[1][i][1 << i] = 1;

	// j가 1~8일때는 양쪽에서 올 수 있지만 0과 9일때는 단방향만 가능.
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < (1 << 10); k++) {
				if (j == 0) { dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD; }
				else if (j == 9) { dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD; }
				else { dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k] + dp[i - 1][j - 1][k]) % MOD; }
			}
		}
	}

	long long answer = 0;

	for (int i = 0; i <= 9; i++) {
		answer = (answer +dp[n][i][(1 << 10) - 1]) % MOD;
	}

	cout << answer;


	return 0;
}