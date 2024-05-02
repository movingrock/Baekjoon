#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;
		int arrA[20];
		int arrB[20];
		for (int i = 0; i < n; i++) cin >> arrA[i];
		for (int i = 0; i < m; i++) cin >> arrB[i];

		int max_sum = 0;

		if (n < m) {
			for (int i = 0; i <= m - n; i++) {
				int sum = 0;
				for (int j = i; j < i + n; j++) {
					sum += arrB[j] * arrA[j - i];
				}
				max_sum = max(max_sum, sum);
			}
		}
		else {
			for (int i = 0; i <= n - m; i++) {
				int sum = 0;
				for (int j = i; j < i + m; j++) {
					sum += arrA[j] * arrB[j - i];
				}
				max_sum = max(max_sum, sum);
			}
		}

		cout << "#" << test_case << " " << max_sum << endl;
	}
	return 0;
}