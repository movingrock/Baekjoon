#include <iostream>

char arr[3072][6143];

using namespace std;

void draw(int x, int y) {
	arr[x][y] = '*';
	arr[x + 1][y - 1] = '*';
	arr[x + 1][y + 1] = '*';

	arr[x + 2][y - 2] = '*';
	arr[x + 2][y - 1] = '*';
	arr[x + 2][y] = '*';
	arr[x + 2][y + 1] = '*';
	arr[x + 2][y + 2] = '*';
}

void backTracking(int n, int x, int y) {
	if (n == 3) {
		draw(x, y);
		return;
	}
	backTracking(n / 2, x, y);
	backTracking(n / 2, x + n / 2, y - n / 2);
	backTracking(n / 2, x + n / 2, y + n / 2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			arr[i][j] = ' ';
		}
	}

	backTracking(n, 0, n-1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0;
}