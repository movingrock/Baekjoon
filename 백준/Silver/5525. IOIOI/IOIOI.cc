#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m; string str;
	cin >> n >> m >> str;

	string p = "I";
	for (int i = 0; i < 2* n; i++) {
		if (i % 2 == 0) p += "O";
		else p += "I";
	}
	
	int cnt = 0;

	for (int i = 0; i < str.length() - n * 2; i++) {
		bool isRight = true;
		int ccc = 0;
		for (int j = i; j < i + (n * 2 + 1); j++) {
			if (str[j] != p[ccc]) isRight = false;
			ccc++;
		}
		if (isRight) cnt++;
	}

	cout << cnt;
	return 0;
}