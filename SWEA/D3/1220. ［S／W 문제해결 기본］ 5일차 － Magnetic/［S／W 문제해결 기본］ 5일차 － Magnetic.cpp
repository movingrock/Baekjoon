#include<iostream>

using namespace std;

int grid[100][100];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> grid[i][j];
			}
		}
		int answer = 0;
		for (int j = 0; j < 100; j++) {
			bool isTrue = false;
			for (int i = 0; i < 100; i++) {
				if (grid[i][j] == 2 && isTrue) {
					answer++;
					isTrue = false;
				}
				if (grid[i][j] == 1) isTrue = true;
			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}