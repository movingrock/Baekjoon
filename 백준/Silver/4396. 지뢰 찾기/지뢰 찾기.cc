#include <iostream>
#include <string>
using namespace std;

char mine[10][10];
char open[10][10];
string ans[10][10];
int n;

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool openMine = false;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			mine[i][j] = str[j];
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			open[i][j] = str[j];
			if (open[i][j] == 'x' && mine[i][j] == '*') openMine = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (openMine && mine[i][j] == '*') ans[i][j] = '*';
			else if(open[i][j] == 'x') {
				int x = i;
				int y = j;
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (InRange(nx, ny) && mine[nx][ny] == '*') cnt++;
				}
				ans[i][j] = to_string(cnt);
			}
			else if (open[i][j] == '.') {
				ans[i][j] = ".";
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
