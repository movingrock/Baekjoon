#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	// 집 사이의 거리
	// left 가 최소값, right가 최대값
	// mid로 그 사이의 적정한 간격을 찾기
	int left = 0;
	int right = v[n-1];
	int dist = 0;
	while (left <= right) {
		int cnt = 1;

		int mid = (left + right) / 2;

		int start = v[0];
		for (int i = 1; i < n; i++) {
			int end = v[i];

			if (end - start >= mid) {
				cnt++;
				start = end;
			}
		}

		if (cnt >= c) {
			dist = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << dist;


	return 0;
}

// c개 선택해서 거리
// 최소거리 최대