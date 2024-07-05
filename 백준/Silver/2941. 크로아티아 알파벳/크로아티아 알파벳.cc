#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	int answer = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c' && i < str.length() - 1 && (str[i + 1] == '=' || str[i + 1] == '-')) {
			answer++; i++;
		}
		else if (str[i] == 'd' && i < str.length() - 2 && str[i + 1] == 'z' && str[i + 2] == '=') {
			answer++;
			i += 2;
		}
		else if (str[i] == 'd' && i < str.length() - 1 && str[i + 1] == '-') {
			answer++;
			i += 1;
		}
		else if (str[i] == 'l' && i < str.length() - 1 && str[i + 1] == 'j') {
			answer++;
			i += 1;
		}
		else if (str[i] == 'n' && i < str.length() - 1 && str[i + 1] == 'j') {
			answer++;
			i += 1;
		}
		else if (str[i] == 's' && i < str.length() - 1 && str[i + 1] == '=') {
			answer++;
			i += 1;
		}
		else if (str[i] == 'z' && i < str.length() - 1 && str[i + 1] == '=') {
			answer++;
			i += 1;
		}
		else answer++;
	}

	cout << answer;

	return 0;
}