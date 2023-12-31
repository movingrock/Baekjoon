#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[26];
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (arr[s[i] - 'a'] == -1) arr[s[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}