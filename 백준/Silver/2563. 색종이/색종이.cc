#include <iostream>

using namespace std;

bool grid[100][100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int a, b;
	while (n--) {
		cin >> a >> b;
		for (int i = a; i < a + 10; i++) {
			for (int j = b; j < b + 10; j++) {
				grid[i][j] = true;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (grid[i][j]) answer++;
		}
	}

	cout << answer;

	return 0;
}