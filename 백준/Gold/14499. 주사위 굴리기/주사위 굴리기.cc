#include <iostream>

using namespace std;

int grid[21][21];

int n, m, x, y, k;

class Dice {
public:
	int bottom = 0;
	int top = 0;
	int forward = 0;
	int right = 0;
	int backward = 0;
	int left = 0;

	void moveEast() {
		int tmp = left;
		left = bottom;
		bottom = right;
		right = top;
		top = tmp;
		y += 1;
		copy();
		cout << top << endl;
	}

	void moveWest() {
		int tmp = right;
		right = bottom;
		bottom = left;
		left = top;
		top = tmp;
		y -= 1;
		copy();
		cout << top << endl;
	}

	void moveNorth() {
		int tmp = forward;
		forward = bottom;
		bottom = backward;
		backward = top;
		top = tmp;
		x -= 1;
		copy();
		cout << top << endl;
	}

	void moveSouth() {
		int tmp = backward;
		backward = bottom;
		bottom = forward;
		forward = top;
		top = tmp;
		x += 1;
		copy();
		cout << top << endl;
	}

	void copy() {
		if (grid[x][y] == 0) {
			grid[x][y] = bottom;
		}
		else {
			bottom = grid[x][y];
			grid[x][y] = 0;
		}
	}
};

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Dice dice;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 1 && InRange(x,y+1)) dice.moveEast();
		else if (num == 2 && InRange(x, y - 1)) dice.moveWest();
		else if (num == 3 && InRange(x - 1, y)) dice.moveNorth();
		else if (num == 4 && InRange(x + 1, y)) dice.moveSouth();
	}

	return 0;
}