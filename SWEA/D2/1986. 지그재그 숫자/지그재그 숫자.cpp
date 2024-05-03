#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	int dp[11] = { 0, };
	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 1) dp[i] = dp[i - 1] + i;
		else dp[i] = dp[i - 1] - i;
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		cout << "#" << test_case << " " << dp[n] << endl;
	}
	return 0;
}