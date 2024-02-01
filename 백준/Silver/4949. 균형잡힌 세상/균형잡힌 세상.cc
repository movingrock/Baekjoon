#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (true) {
		stack<int> s;
		string str;
		bool isAnswer = true;

		getline(cin, str);
		if (str == ".") break;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') s.push(str[i]);
			else if(str[i] == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else isAnswer = false;
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else isAnswer = false;
			}
		}

		if (s.empty() && isAnswer) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
}