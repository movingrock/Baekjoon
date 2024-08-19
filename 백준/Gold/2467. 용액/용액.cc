#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int arr[100001];

int answer = INT_MAX;

int ansL= 0, ansR = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = n - 1;
	while (left < right) {
		if (abs(arr[left] + arr[right]) < abs(answer)) {
			ansL = arr[left];
			ansR = arr[right];
			answer = arr[left] + arr[right];
		}

		if (arr[left] > 0)  right--;
		else if (arr[right] < 0) left++;
		else {
			if (abs(arr[left]) > abs(arr[right])) left++;
			else right--;
		}

	}

	cout << ansL << " " << ansR;

	return 0;
}