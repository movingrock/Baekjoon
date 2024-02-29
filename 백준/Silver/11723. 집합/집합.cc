#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int arr[21] = { 0, };

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str; int x;
		cin >> str;
		if (str == "add") {
			cin >> x;
			arr[x] = 1;
		}
		else if (str == "remove") {
			cin >> x;
			arr[x] = 0;
		}
		else if (str == "check") {
			cin >> x;
			if (arr[x] == 1) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "toggle") {
			cin >> x;
			if (arr[x] == 1) arr[x] = 0;
			else arr[x] = 1;
		}
		else if (str == "all") {
			for (int j = 1; j <= 20; j++) {
				arr[j] = 1;
			}
		}
		else if (str == "empty") {
			for (int j = 1; j <= 20; j++) {
				arr[j] = 0;
			}
		}

	}

	return 0;
}