#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	int arr[5] = { 2, 3, 5, 7, 11 };


	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int cnt[5] = { 0, };

		for (int i = 0; i < 5; i++) {
			while (n % arr[i] == 0) {
				n /= arr[i];
				cnt[i]++;
			}
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < 5; i++) {
			cout << cnt[i] << " ";
		}
		cout << endl;
	}
	return 0;
}