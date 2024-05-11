#include <iostream>

using namespace std;

int grid[5][5];
bool check[5][5] = { 0, };
int answer = 0;

void findPos(int n) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[i][j] == n) check[i][j] = true;
		}
	}
}

void Check() {
	for (int i = 0; i < 5; i++) {
		bool isAlltrue = true;
		for (int j = 0; j < 5; j++) {
			if (check[i][j] == 0) isAlltrue = false;
		}
		if (isAlltrue) answer++;
	}

	for (int i = 0; i < 5; i++) {
		bool isAlltrue = true;
		for (int j = 0; j < 5; j++) {
			if (check[j][i] == 0) isAlltrue = false;
		}
		if (isAlltrue) answer++;
	}

	{
		bool isAlltrue = true;
		for (int i = 0; i < 5; i++) {
			if (check[i][4 - i] == 0) isAlltrue = false;
		}
		if (isAlltrue) answer++;
	}

	{
		bool isAlltrue = true;
		for (int i = 0; i < 5; i++) {
			if (check[i][i] == 0) isAlltrue = false;
		}
		if (isAlltrue) answer++;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for(int j = 0; j<5; j++){
			cin >> grid[i][j];
		}
	}

	for (int i = 1; i <= 25; i++) {
		int num;
		cin >> num;
		findPos(num);

		answer = 0;
		if(i>=12) Check();

		if (answer >= 3) {
			cout << i;
			return 0;
		}
	}

	return 0;
}