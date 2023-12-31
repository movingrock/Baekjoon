#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string str;
		cin >> str;
		if ((str[0] - '0') == 0) break;

		bool isPalindrome = true;

		for (int i = 0; i < (str.length() / 2); i++) {
			if (str[i] != str[str.length() - 1 - i]) isPalindrome = false;
		}

		if (isPalindrome) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}