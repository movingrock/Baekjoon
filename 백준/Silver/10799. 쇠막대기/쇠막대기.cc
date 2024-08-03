#include <iostream>
#include <stack>

using namespace std;

long long dp[1001][10];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	stack<char> s;

	int answer = 0;

	for (int i = 0; i < str.length(); i++) {
		if (i < str.length() - 1 && str[i] == '(' && str[i + 1] == '(') { 
			s.push('(');
		}
		else if (i < str.length() - 1 && str[i] == '(' && str[i + 1] == ')') {
			answer += s.size();
			i++;
		}
		else if (str[i] == ')') {
			answer += 1;
			s.pop();
		}
	}

	cout << answer;

	return 0;
}