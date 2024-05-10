#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	if (str == "0") {
		cout << 0;
		return 0;
	}
	string ans = "";
	for (int i = 0; i < str.length(); i++) {
		int n = str[i] - '0';
		ans += to_string(n / 4);
		ans += to_string(n % 4 / 2);
		ans += to_string(n % 4 % 2);
	}

	bool isfirst = false;
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == '1') {
			isfirst = true;
		}
		if (isfirst) {
			cout << ans[i];
		}
	}

	return 0;
}