#include <iostream>
#include <set>
using namespace std;

struct Pos {
	int x;
	int y;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	char keyboard[3][10] = {
		{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
		{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ' '},
		{'z', 'x', 'c', 'v', 'b', 'n', 'm', ' ', ' ', ' '},
	};

	char sl, sr;
	cin >> sl >> sr;

	Pos l;
	Pos r;

	set<char> leftHand;
	char lh[14] = { 'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v' };
	for (int i = 0; i < 14; i++) {
		leftHand.insert(lh[i]);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (keyboard[i][j] == sl) {
				l.x = i;
				l.y = j;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (keyboard[i][j] == sr) {
				r.x = i;
				r.y = j;
			}
		}
	}

	string str;
	cin >> str;

	int answer = 0;

	for (int x = 0; x < str.length(); x++) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				if (keyboard[i][j] == str[x]) {
					if (leftHand.find(str[x]) != leftHand.end()) {
						answer += abs(i - l.x) + abs(j - l.y);
						l.x = i;
						l.y = j;
					}
					else {
						answer += abs(i - r.x) + abs(j - r.y);
						r.x = i;
						r.y = j;
					}

				}
			}
		}
	}

	cout << answer + str.length();

	return 0;
}