#include<iostream>

using namespace std;

int money[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int arr[8] = { 0, };
		int cnt = 0;
		while (n != 0) {
			arr[cnt] = n / money[cnt];
			n %= money[cnt];
			cnt++;
		}

		cout << "#" << test_case << endl;
		for (int i = 0; i < 8; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}