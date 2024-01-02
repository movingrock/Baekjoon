#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int arr[10001] = { 0, };
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}