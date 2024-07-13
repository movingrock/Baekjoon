#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	answer.push_back(v[0]);

	for (int i = 1; i < n; i++) {
		if (v[i] > answer.back()) answer.push_back(v[i]);
		else {
			int left = 0;
			int right = answer.size() - 1;
			
			while (left < right) {
				int mid = (left + right) / 2;

				if (answer[mid] >= v[i]) right = mid;
				else left = mid + 1;
			}
			
			answer[right] = v[i];
		}
	}
	cout << answer.size();


	return 0;
}