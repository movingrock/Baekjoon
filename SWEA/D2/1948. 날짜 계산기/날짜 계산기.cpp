#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int m1, d1, m2, d2;
		cin >> m1 >> d1 >> m2 >> d2;

		int ans = 0;

		for (int i = m1; i <= m2; i++) {
			if (m1 == m2) ans = d2 - d1;
			else if (i == m1) ans += days[m1] - d1;
			else if (i == m2) ans += d2;
			else ans += days[i];
		}

		cout << "#" << test_case << " " << ans+1 << endl;
	}
	return 0;
}