#include<iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int grid[9][9];
		bool visited[10] = { 0, };
		bool isTrue = true;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> grid[i][j];
			}
		}

		// 가로 검사
		for (int i = 0; i < 9; i++) {
			memset(visited, false, sizeof(visited));
			for (int j = 0; j < 9; j++) {
				visited[grid[i][j]] = true;
			}
			for (int j = 1; j <= 9; j++) {
				if (!visited[j]) isTrue = false;
			}
		}

		// 세로 검사
		for (int i = 0; i < 9; i++) {
			memset(visited, false, sizeof(visited));
			for (int j = 0; j < 9; j++) {
				visited[grid[j][i]] = true;
			}
			for (int j = 1; j <= 9; j++) {
				if (!visited[j]) isTrue = false;
			}
		}

		// 사각형 검사
		for (int i = 0; i <= 6; i += 3) {
			for (int j = 0; j <= 6; j += 3) {
				memset(visited, false, sizeof(visited));

				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						visited[grid[k][l]] = true;
					}
				}


				for (int x = 1; x <= 9; x++) {
					if (!visited[x]) isTrue = false;
				}
			}
		}

		int ans;
		if (isTrue) ans = 1;
		else ans = 0;

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}