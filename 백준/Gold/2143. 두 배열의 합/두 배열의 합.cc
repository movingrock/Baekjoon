#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int a[MAX];
int b[MAX];

vector<int> aSum;
vector<int> bSum;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t, n, m;
	cin >> t;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	
	for (int i = 1; i <= n; i++) {
		int sum = a[i];
		aSum.push_back(sum);
		for (int j = i + 1; j <= n; j++) {
			sum += a[j];
			aSum.push_back(sum);
		}
	 }

	for (int i = 1; i <= m; i++) {
		int sum = b[i];
		bSum.push_back(sum);
		for (int j = i + 1; j <= m; j++) {
			sum += b[j];
			bSum.push_back(sum);
		}
	}

	sort(bSum.begin(), bSum.end());
	long long ans = 0;
	for (int i = 0; i < aSum.size(); i++) {
		int target = t - aSum[i];

		int lo = lower_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
		int hi = upper_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
		ans += (hi - lo);
	}

	cout << ans;

	return 0;
}