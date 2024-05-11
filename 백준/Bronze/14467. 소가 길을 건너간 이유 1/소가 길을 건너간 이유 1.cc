#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int num, loc;
	int arr[11];
	int answer = 0;
	for (int i = 1; i < 11; i++) {
		arr[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		cin >> num >> loc;
		if (arr[num] == -1) arr[num] = loc;
		else if (arr[num] != loc) {
			arr[num] = loc;
			answer++;
		}
	}

	cout << answer;

	return 0;
}