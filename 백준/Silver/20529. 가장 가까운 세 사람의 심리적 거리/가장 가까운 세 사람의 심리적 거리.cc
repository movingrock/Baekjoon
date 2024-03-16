#include <iostream>
#include <climits>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<string> v;
		for (int j = 0; j < n; j++) {
			string mbti;
			cin >> mbti;
			v.push_back(mbti);
		}

		// 이걸 어캐 알아
		if (n > 32) {
			cout << 0 << "\n";
			continue;
		}

		int min_sum = INT_MAX;

		for (int j = 0; j < n - 2; j++) {
			for (int k = j + 1; k < n - 1; k++) {
				for (int l = k + 1; l < n; l++) {
					int sum = 0;
					for (int x = 0; x < 4; x++) {
						if (v[j][x] != v[k][x]) sum++;
						if (v[l][x] != v[k][x]) sum++;
						if (v[j][x] != v[l][x]) sum++;
					}
					min_sum = min(min_sum, sum);
				}
			}
		}

		cout << min_sum << "\n";
	}
	return 0;
}