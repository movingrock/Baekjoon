#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<int> v(100);
		for (int i = 0; i < 100; i++) {
			cin >> v[i];
		}

		while (n--) {
			v[0]++;
			v[99]--;
			sort(v.begin(), v.end());
		}

		cout << "#" << test_case << " " << v[99] - v[0] << endl;
	}
	return 0;
}