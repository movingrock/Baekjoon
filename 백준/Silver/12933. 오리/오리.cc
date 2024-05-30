#include <iostream>

using namespace std;

bool duck[501] = { 0, };
int length[501] = { 0, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	int cnt = 0;
	bool isWrong = false;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'q') { // 기존 오리가 낸 소리인지 판별
			bool flag = false;
			for (int i = 1; i <= cnt; i++) {
				if (duck[i] == false) {
					duck[i] = true;
					flag = true;
					length[i] += 1;
					break;
				}
			}
			if (!flag) { // 새 오리가 있음.
				cnt++;
				duck[cnt] = true;
				length[cnt] += 1;
			}
		}
		else if (str[i] == 'u' ) {
			bool flag = false;
			for (int i = 0; i <= cnt; i++) {
				if (duck[i] == true && length[i] == 1) {
					length[i] += 1;
					flag = true;
					break;
				}
			}
			if (!flag) {
				isWrong = true;
				break;
			}
		}
		else if (str[i] == 'a') {
			bool flag = false;
			for (int i = 0; i <= cnt; i++) {
				if (duck[i] == true && length[i] == 2) {
					length[i] += 1;
					flag = true;
					break;
				}
			}
			if (!flag) {
				isWrong = true;
				break;
			}
		}
		else if (str[i] == 'c') {
			bool flag = false;
			for (int i = 0; i <= cnt; i++) {
				if (duck[i] == true && length[i] == 3) {
					length[i] += 1;
					flag = true;
					break;
				}
			}
			if (!flag) {
				isWrong = true;
				break;
			}
		}
		else if (str[i] == 'k') {
			bool flag = false;

			for (int i = 0; i <= cnt; i++) {
				if (duck[i] == true && length[i] == 4) {
					length[i] = 0;
					flag = true;
					duck[i] = false;
					break;
				}
			}
			if (!flag) {
				isWrong = true;
				break;
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {
		if (duck[i] == true) isWrong = true;
	}

	if (isWrong) cout << -1;
	else cout << cnt;

	return 0;
}