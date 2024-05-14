#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int grid[100][100];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc; cin >> tc;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> grid[i][j];
			}
		}
		int answer = 0;

		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += grid[i][j];
			}
			answer = max(answer, sum);
		}

		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += grid[j][i];
			}
			answer = max(answer, sum);
		}

		{
			int sum = 0;
			for (int i = 0; i < 100; i++) {
				sum += grid[i][i];
			}
			answer = max(answer, sum);
		}

		{
			int sum = 0;
			for (int i = 0; i < 100; i++) {
				sum += grid[i][99-i];
			}
			answer = max(answer, sum);
		}

		cout << "#" << test_case << " " << answer << endl;

	}
	return 0;
}