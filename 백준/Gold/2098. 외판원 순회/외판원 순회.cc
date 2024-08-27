#include <iostream>
#include <cstring>
#include <climits>

#define INF 987654321

using namespace std;

int w[16][16];
int dp[16][1 << 16]; // dp[i][j] i번째 도시에서의, n까지의 이동한 도시를 표현한 비트 j 일때의 비용
//2진수 1,0000,0000,0000,0000 10진수 65536
int n;

int answer;

int dfs(int cur, int bit) {
	if (bit == answer) {
		return w[cur][0] == 0 ? INF : w[cur][0];
	}

	if (dp[cur][bit] != -1) return dp[cur][bit];
	dp[cur][bit] = INF;

	for (int i = 0; i < n; i++) {
		if (w[cur][i] == 0) continue;
		if ((bit & (1 << i)) == (1 << i)) continue;

		dp[cur][bit] = min(dp[cur][bit], w[cur][i] + dfs(i, bit | 1 << i));
	}
	return dp[cur][bit];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	answer = (1 << n) - 1;
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1);

	return 0;
}