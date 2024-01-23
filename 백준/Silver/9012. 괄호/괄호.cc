#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		bool isAnswer = true;
		string str;
		cin >> str;
		stack<char>s;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') s.push('(');
			else {
				if (s.empty()) isAnswer = false;
				else s.pop();
			}
		}

		if (s.empty() && isAnswer) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}