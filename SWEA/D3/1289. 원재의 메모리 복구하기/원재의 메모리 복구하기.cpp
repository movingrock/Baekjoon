#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;

		string answer = "";
		for (int i = 0; i < str.length(); i++) {
			answer += '0';
		}

		int cnt = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '1' && answer[i] == '0') {
				for (int j = i; j < str.length(); j++) {
					answer[j] = '1';
				}
				cnt++;
			}
			else if (str[i] == '0' && answer[i] == '1') {
				for (int j = i; j < str.length(); j++) {
					answer[j] = '0';
				}
				cnt++;
			}
			if (str == answer) break;
		}


		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;
}