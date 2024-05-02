#include<iostream>

using namespace std;

void rotation(int &) {

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int grid[7][7];
		int grid90[7][7];
		int grid180[7][7];
		int grid270[7][7];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				grid90[i][j] = grid[n - 1 - j][i];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				grid180[i][j] = grid90[n - 1 - j][i];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				grid270[i][j] = grid180[n -1 - j][i];
			}
		}
		

		cout << "#" << test_case << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << grid90[i][j];
			}
			cout << " ";
			for (int j = 0; j < n; j++) {
				cout << grid180[i][j];
			}
			cout << " ";
			for (int j = 0; j < n; j++) {
				cout << grid270[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}