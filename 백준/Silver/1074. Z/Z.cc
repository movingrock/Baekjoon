#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int ans = 0;

void Check(int l, int x, int y) { // X, Y 는 왼쪽 위 좌표
	if (r == x && y == c) {
		cout << ans;
		return;
	}
	else if (r < x+l && c < y+l && r >= x && c >= y) {
		Check(l / 2, x, y);
		Check(l / 2, x, y + l / 2);
		Check(l / 2, x + l / 2, y);
		Check(l / 2, x + l / 2, y + l / 2);
	}
	else {
		ans += l * l;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> r >> c;

	Check(pow(2, n), 0, 0);



	return 0;
}