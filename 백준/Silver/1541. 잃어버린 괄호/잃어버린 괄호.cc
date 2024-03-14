#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	string num;
	int sum = 0;
	bool isMinus = false;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0') {
			if (isMinus) {
				sum -= stoi(num);
				num = "";
			}
			else {
				sum += stoi(num);
				num = "";
			}
		}
		else {
			num += str[i];
		}

		if (str[i] == '-') isMinus = true;
	}

	cout << sum;

	return 0;
}