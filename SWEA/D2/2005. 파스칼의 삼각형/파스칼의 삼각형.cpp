#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
		int grid[10][10];


		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) grid[i][j] = 1;
				else grid[i][j] = grid[i - 1][j - 1] + grid[i - 1][j];
			}
		}
		cout << "#" << test_case << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}