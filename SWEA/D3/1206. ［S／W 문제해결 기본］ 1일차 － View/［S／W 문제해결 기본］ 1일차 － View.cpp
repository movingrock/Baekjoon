#include<iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[1001] = { 0, };

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr[i] = num;
		}

		int ans = 0;
		for (int i = 2; i < n - 2; i++) {
			int max_h = max({ arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2] });
			if (arr[i] > max_h) ans += arr[i] - max_h;
		}

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}