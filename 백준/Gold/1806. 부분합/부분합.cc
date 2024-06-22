#include <iostream>
#include <vector>

#define INF 100001

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long n, s;
	cin >> n >> s;
	vector<long long> v(100001, 0);
	vector<long long> sum(100001, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	long long ans = INF;
	long long l = 0, r = 1;
	while (l < r) {
		if (r > n) break;
		if (sum[r] - sum[l] >= s) {
			ans = min(ans, r - l);
			l++;
		}
		else if (sum[r] - sum[l] < s) r++;
	}

	if (ans == INF) cout << 0;
	else cout << ans;

	return 0;
}