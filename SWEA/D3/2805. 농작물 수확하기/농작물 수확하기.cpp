#include<iostream>

using namespace std;

int grid[50][50];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str; cin >> str;
			for (int j = 0; j < n; j++) {
				grid[i][j] = str[j] - '0';
			}
		}

		int answer = 0;
		for (int i = 0; i < n; i++) {
			if (i <= n / 2) {
				for (int j = n / 2 - i; j <= n / 2 + i; j++) {
					answer += grid[i][j];
				}
			}
			else {
				for (int j = (n/2 - (n-1-i)); j <= (n / 2 + n - 1 - i); j++) {
					answer += grid[i][j];
				}

			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}