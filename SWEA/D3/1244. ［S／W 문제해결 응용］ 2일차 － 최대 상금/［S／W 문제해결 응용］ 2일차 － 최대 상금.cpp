#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str;
int change;
int ans = 0;

void dfs(int index, int cnt) {
	if (change == cnt) {
		ans = max(ans, stoi(str));
		return;
	}

	for (int i = index; i < str.length() - 1; i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] <= str[j]) {
				swap(str[i], str[j]);
				dfs(i, cnt + 1);
				swap(str[i], str[j]);
			}

			if (i == str.length() - 2 && j == str.length() - 1) {
				swap(str[i], str[j]);
				dfs(i, cnt + 1);
				swap(str[i], str[j]);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> str >> change;
		ans = 0;
		dfs(0, 0);

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}