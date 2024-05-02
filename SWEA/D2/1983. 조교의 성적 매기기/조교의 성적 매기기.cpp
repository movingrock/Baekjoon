#include<iostream>

using namespace std;

string score[10] = { "A+", "A0", "A-", "B+", "B0","B-", "C+", "C0" ,"C-", "D0" };

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		double arr[101];
		int n, k;
		cin >> n >> k;

		for (int i = 1; i <= n; i++) {
			double a, b, c;
			cin >> a >> b >> c;
			double sum = a * 0.35 + b * 0.45 + c * 0.20;
			arr[i] = sum;
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] > arr[k]) cnt++;
		}

		string ans;
		ans = score[cnt / (n / 10)];
		
		cout << "#" << test_case << " " << ans << endl;

	}
	return 0;
}