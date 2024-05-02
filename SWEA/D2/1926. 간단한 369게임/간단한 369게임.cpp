#include<iostream>

using namespace std;

int isThree(int n) {
	int cnt = 0;
	while (n != 0) {
		if (n % 10 == 3 || n % 10 == 6 || n % 10 == 9) cnt++;
		n /= 10;
	}
	return cnt;
}

int main(int argc, char** argv)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (isThree(i) > 0) {
			for (int j = 0; j < isThree(i); j++) cout << "-";
			cout << " ";
		}
		else cout << i << " ";
	}

	return 0;
}