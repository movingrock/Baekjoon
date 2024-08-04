#include <iostream>
#include <cmath>

using namespace std;

class Gear {
public:
	bool canMove = false;
	int arr[8]; //12시부터 0~7

	void move(int n) {
		if (n == 1) moveClock();
		else moveCounter();
	}

	void moveClock() {
		int tmp = arr[7];
		for (int i = 7; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = tmp;
	}

	void moveCounter() {
		int tmp = arr[0];
		for (int i = 0; i < 7; i++) {
			arr[i] = arr[i + 1];
		}
		arr[7] = tmp;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Gear gear[5]; // 1~4

	for (int i = 1; i <= 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++) {
			gear[i].arr[j] = str[j] - '0';
		}
	}

	int k;
	cin >> k;
	while (k--) {
		int num, dir;
		cin >> num >> dir;

		for (int i = 1; i < 5; i++) {
			gear[i].canMove = false;
		}

		int dir1 = dir;
		int dir2 = dir;
		for (int i = num + 1; i <= 4; i++) {
			if (gear[i].arr[6] != gear[i - 1].arr[2]) {
				gear[i].canMove = true;
			}
			else break;
		}
		for (int i = num-1; i >= 1; i--) {
			if (gear[i].arr[2] != gear[i + 1].arr[6]) {
				gear[i].canMove = true;
			}
			else break;
		}


		for (int i = num + 1; i <= 4; i++) {
			if (gear[i].canMove) {
				dir1 *= -1;
				gear[i].move(dir1);
			}
			else break;
		}

		for (int i = num-1; i >= 1; i--) {
			if (gear[i].canMove) {
				dir2 *= -1;
				gear[i].move(dir2);
			}
			else break;
		}

		gear[num].move(dir);
	}

	int answer = 0;
	for (int i = 1; i <= 4; i++) {
		answer += (gear[i].arr[0] == 1 ? pow(2, i-1) : 0);
	}

	cout << answer;

	return 0;
}

