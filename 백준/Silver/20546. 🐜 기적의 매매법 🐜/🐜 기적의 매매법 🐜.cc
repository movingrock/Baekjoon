#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int cash;
	cin >> cash;
	int stock;
	int arr[14];
	for (int i = 0; i < 14; i++) {
		cin >> arr[i];
	}

	int cashJ = cash;
	int stockJ = 0;

	int cashS = cash;
	int stockS = 0;

	// 준현
	for (int i = 0; i < 14; i++) {
		if (arr[i] <= cashJ) {
			stockJ = cashJ / arr[i];
			cashJ = cashJ % arr[i];
		}
	}

	// 성현
	int upCnt = 0;
	int downCnt = 0;
	for (int i = 1; i < 14; i++) {
		if (arr[i] > arr[i - 1]) {
			upCnt++;
			downCnt = 0;
		}
		else if (arr[i] < arr[i - 1]) {
			downCnt++;
			upCnt = 0;
		}

		if (upCnt >= 3) {
			cashS += stockS * arr[i];
			stockS = 0;
		}
		if (downCnt >= 3) {
			stockS += cashS / arr[i];
			cashS %= arr[i];
		}
	}

	if (cashJ + stockJ * arr[13] > cashS + stockS * arr[13]) cout << "BNP";
	else if (cashJ + stockJ * arr[13] < cashS + stockS * arr[13]) cout << "TIMING";
	else  cout << "SAMESAME";


	return 0;
}