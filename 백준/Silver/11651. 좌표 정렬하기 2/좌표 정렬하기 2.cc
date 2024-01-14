#include <iostream>
#include <algorithm>

using namespace std;

class Pos {
public:
	int x;
	int y;
};

int cmp(Pos p1, Pos p2) {
	if (p1.y != p2.y) return p1.y < p2.y;
	else return p1.x < p2.x;
}

int main() {
	int n;
	cin >> n;
	Pos pos[100000];
	for (int i = 0; i < n; i++) {
		cin >> pos[i].x >> pos[i].y;
	}

	sort(pos, pos + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << pos[i].x << " " << pos[i].y << "\n";
	}

	return 0;
}