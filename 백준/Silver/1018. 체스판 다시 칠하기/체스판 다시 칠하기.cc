#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

char boardB[8][8] = {
	{'W', 'B','W', 'B','W', 'B','W', 'B'},
	{'B','W', 'B','W', 'B','W', 'B', 'W'},
	{'W', 'B','W', 'B','W', 'B','W', 'B'},
	{'B','W', 'B','W', 'B','W', 'B', 'W'},
	{'W', 'B','W', 'B','W', 'B','W', 'B'},
	{'B','W', 'B','W', 'B','W', 'B', 'W'},
	{'W', 'B','W', 'B','W', 'B','W', 'B'},
	{'B','W', 'B','W', 'B','W', 'B', 'W'}
};

char boardW[8][8] = {
	{'B','W', 'B','W', 'B','W', 'B', 'W'},
	{'W', 'B','W', 'B','W', 'B','W', 'B'},
	{'B','W', 'B','W', 'B','W', 'B', 'W'},
	{'W', 'B','W', 'B','W', 'B','W', 'B'},
	{'B','W', 'B','W', 'B','W', 'B', 'W'},
	{'W', 'B','W', 'B','W', 'B','W', 'B'},
	{'B','W', 'B','W', 'B','W', 'B', 'W'},
	{'W', 'B','W', 'B','W', 'B','W', 'B'}
};


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	int grid[50][50];
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			grid[i][j] = str[j];
		}
	}


	int min_ans = INT_MAX;
	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) {
			int boardB_cnt = 0;
			int boardW_cnt = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (grid[k][l] != boardB[k - i][l - j]) boardB_cnt++;
					if (grid[k][l] != boardW[k - i][l - j]) boardW_cnt++;

				}
			}
			min_ans = min(min_ans, min(boardB_cnt, boardW_cnt));
		}
	}

	cout << min_ans;
	return 0;
}