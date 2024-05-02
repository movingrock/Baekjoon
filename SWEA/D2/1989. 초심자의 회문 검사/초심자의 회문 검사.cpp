#include<iostream>

using namespace std;

void rotation(int &) {

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;

		bool isTrue = true;
		for (int i = 0; i < str.length() / 2; i++) {
			if (str[i] != str[str.length() - 1 - i]) {
				isTrue = false;
				break;
			}
		}
		
		int ans;
		if (isTrue) ans = 1;
		else ans = 0;

		cout << "#" << test_case << " " << ans << endl;

	}
	return 0;
}