#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	getline(cin, str);

	string tmp = "";
	bool isTag = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') {
			reverse(tmp.begin(), tmp.end());
			cout << tmp;
			tmp = "";
			isTag = true;
			tmp += str[i];
		}
		else if (str[i] == '>' && isTag) {
			tmp += str[i];
			cout << tmp;
			tmp = "";
			isTag = false;
		}
		else if (isTag) {
			tmp += str[i];
		}
		else if (!isTag && str[i] != ' ') {
			tmp += str[i];
		}
		else if (!isTag && str[i] == ' ') {
			reverse(tmp.begin(), tmp.end());
			cout << tmp; cout << " ";
			tmp = "";
		}
	}

	reverse(tmp.begin(), tmp.end());
	cout << tmp;

	return 0;
}