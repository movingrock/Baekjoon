#include <iostream>
#include <cstring>

using namespace std;

int n;
int answer = 0;
int rows[10];

bool Check(int x) {
	for (int i = 0; i < x; i++) {
		if (rows[i] == rows[x] || abs(rows[i] - rows[x]) == x - i) return false;
	}
	return true;
}

void NQueen(int cnt) {
	if (cnt == n) {
		answer++; return;
	}

	for (int i = 0; i < n; i++) {
		rows[cnt] = i;
		if (Check(cnt)) {
			NQueen(cnt + 1);
		}
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		answer = 0;
		memset(rows, 0, sizeof(rows));
		NQueen(0);

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}