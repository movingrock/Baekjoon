#include <iostream>

using namespace std;

int col[15];
int n;
int ans = 0;

bool isOk(int x) {
	for (int i = 0; i < x; i++) {
		if (col[x] == col[i] || x - i == abs(col[x] - col[i])) return false;
	}
	return true;
}

void nQueen(int x) {
	if (n == x) ans++;
	else {
		for (int i = 0; i < n; i++) {
			col[x] = i;
			if (isOk(x)) nQueen(x + 1);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	nQueen(0);
	cout << ans;
	return 0;
}