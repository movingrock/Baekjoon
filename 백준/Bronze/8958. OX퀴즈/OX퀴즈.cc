#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	string str;
	for (int i = 0; i < t; i++) {
		cin >> str;
		int score = 0;
		int plusScore = 1;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') { score += plusScore; plusScore += 1; }
			else plusScore = 1;
		}

		cout << score << "\n";
	}

	return 0;
}