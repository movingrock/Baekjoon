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
		int ans = 0;
		cin >> str;

		for (int i = 0; i < str.length(); i++) { // 시작지점
			bool flag = false;
			for (int j = 1; j < str.length() - i; j++) { // 길이
				bool isTrue = true;
				for (int k = 0; k < str.length() - j; k+= j) {
					if (str.substr(i, j) != str.substr(k, j)) {
						isTrue = false;
						break;
					}
				}
				if (isTrue) { ans = j - i; flag = true;  break; }
			}
			if (flag) break;
		}

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}