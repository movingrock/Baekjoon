#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tang[200001];
vector<int> fruit(10, 0);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i =0; i<n; i++){
		cin >> tang[i];
	}

	int ans = 0;
	int left = 0;
	int right = 0;

	while (right < n) {
		fruit[tang[right++]]++;

		while (10 - count(fruit.begin(), fruit.end(), 0) > 2) fruit[tang[left++]]--;
		ans = max(ans, right - left);
	}

	cout << ans;

	return 0;
}