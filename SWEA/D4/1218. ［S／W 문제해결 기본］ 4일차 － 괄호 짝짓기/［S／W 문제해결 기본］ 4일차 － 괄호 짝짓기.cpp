#include<iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		stack<char> s;
		int n;
		string str;

		cin >> n;
		cin >> str;

		bool isTrue = true;
		
		for (int i = 0; i < n; i++) {
			if (str[i] == '(') s.push('(');
			else if (str[i] == '[') s.push('[');
			else if (str[i] == '{') s.push('{');
			else if (str[i] == '<') s.push('<');
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else { isTrue = false; break; }
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else { isTrue = false; break; }
			}
			else if (str[i] == '}') {
				if (!s.empty() && s.top() == '{') s.pop();
				else { isTrue = false; break; }
			}
			else if (str[i] == '>') {
				if (!s.empty() && s.top() == '<') s.pop();
				else { isTrue = false; break; }
			}
		}


		cout << "#" << test_case << " ";
		if (s.empty() && isTrue) cout << 1 << endl;
		else cout << 0 << endl;

	}
	return 0;
}