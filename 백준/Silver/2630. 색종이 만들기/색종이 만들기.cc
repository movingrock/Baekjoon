#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int grid[128][128];
int white = 0;
int blue = 0;

void Divide(int n, int x, int y) {
	bool isAllBlue = true;
	bool isAllWhite = true;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (grid[i][j] != 1) { isAllBlue = false; }
			if (grid[i][j] != 0) { isAllWhite = false; }
			
		}
	}

	if (isAllWhite) white++;
	if (isAllBlue) blue++;


	if (n != 1 && isAllBlue == false && isAllWhite == false) {
		n /= 2;
		Divide(n, x, y);
		Divide(n, x + n, y);
		Divide(n, x, y + n);
		Divide(n, x + n, y + n);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	Divide(n, 0, 0);

	cout << white << "\n" << blue;

	return 0;
}