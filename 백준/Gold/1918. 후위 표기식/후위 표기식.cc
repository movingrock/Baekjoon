#include <iostream>
#include <stack>

using namespace std;

// (가 나오면 그냥 넣어줌
// )가 나오면 ( 까지 다 빼고 출력
// * / 가 들어오면 top에 * / 가 있는 경우만 빼줌
// + - 가 들어오면 ( 가 아닌 이상 다 빼줌
// 마지막에 스택에 남아있는거 위에서부터 다 빼줌

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') cout << str[i];


		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}