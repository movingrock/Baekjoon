#include<iostream>

using namespace std;

char grid[100][100];

bool isPalindrome(int i, int j, int len) {
	for (int k = 0; k < len / 2; k++) {
		if (grid[i][j + k] != grid[i][j + len - 1 - k]) return false;
	}
	return true;
}

bool isPalindrome2(int i, int j, int len) {
	for (int k = 0; k < len / 2; k++) {
		if (grid[i + k][j] != grid[i + len - 1 - k][j]) return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc; cin >> tc;
		int max_len = 0;

		for (int i = 0; i < 100; i++) {
			string str; cin >> str;
			for (int j = 0; j < 100; j++) {
				grid[i][j] = str[j];
			}
		}

		// 가로
		for (int len = 1; len <= 100; len++) {
			for (int i = 0; i < 100; i++) { 
				for (int j = 0; j < 100 - len + 1; j++) {
					if (isPalindrome(i, j, len)) max_len = max(max_len, len);
				}
			}
		}

		// 세로
		for (int len = 1; len <= 100; len++) {
			for (int i = 0; i < 100 - len + 1; i++) {
				for (int j = 0; j < 100; j++) {
					if (isPalindrome2(i, j, len)) max_len = max(max_len, len);
				}
			}
		}



		cout << "#" << tc << " " << max_len << endl;
	}
	return 0;
}