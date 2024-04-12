#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str, bomb;
	cin >> str >> bomb;

	string ans = "";

	for (int i = 0; i < str.length(); i++) {
		ans += str[i];
		if (ans.back() == bomb.back() && ans.length() >= bomb.length()) {
			bool isPossible = true;
			for (int j = 0; j < bomb.length(); j++) {
				if (ans[ans.length() - bomb.length() + j] != bomb[j]) {
					isPossible = false;
					break;
				}
			}

			if (isPossible) {
				for (int j = 0; j < bomb.length(); j++) {
					ans.pop_back();
				}
			}
		}
	}

	if (ans.empty()) cout << "FRULA";
	else cout << ans;

	return 0;
}