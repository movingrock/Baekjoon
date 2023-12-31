#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int i = 1;
	int ans = 1;
	while (n > i) {
		i += (6 * ans);
		ans++;
	}
	cout << ans;
	return 0;
}