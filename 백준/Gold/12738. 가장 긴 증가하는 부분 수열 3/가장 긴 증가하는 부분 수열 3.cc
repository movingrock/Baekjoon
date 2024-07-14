#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		// 처음에 값을 넣어주거나 새로들어올 값이 더 클때 answer에 넣어줌.
		if (ans.size() == 0 || ans.back() < arr[i]) ans.push_back(arr[i]);
		else {
			int left = 0;
			int right = ans.size() - 1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (ans[mid] >= arr[i]) right = mid;
				else left = mid + 1;
			}
			ans[left] = arr[i];
		}
	}
	cout << ans.size();

	return 0;
}