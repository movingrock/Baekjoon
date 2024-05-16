#include<iostream>

using namespace std;

char grid[8][8];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int answer = 0;

		for (int i = 0; i < 8; i++) {
			string str; cin >> str;
			for (int j = 0; j < 8; j++) {
				grid[i][j] = str[j];
			}
		}

		// 가로
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8-n+1; j++) { // 시작
				bool isTrue = true;
				for (int k = 0; k < n/2; k++) {
					if (grid[i][j + k] != grid[i][j + (n - 1) - k]) isTrue = false;
				}
				if (isTrue) answer++;
			}
		}

		// 세로
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - n + 1; j++) { // 시작
				bool isTrue = true;
				for (int k = 0; k < n / 2; k++) {
					if (grid[j + k][i] != grid[j + (n - 1) - k][i]) isTrue = false;
				}
				if (isTrue) answer++;
			}
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}