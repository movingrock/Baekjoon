#include<iostream>
#include <climits>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		int min_dist = INT_MAX;
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			num = abs(num);
			if (min_dist > num) {
				min_dist = num;
				cnt = 1;
			}
			else if (min_dist == num) cnt++;
		}
		
		cout << "#" << test_case << " " << min_dist << " " << cnt << endl;
	}
	return 0;
}