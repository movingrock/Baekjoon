#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<double> v;
		for (int i = 0; i < 10; i++) {
			double num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		double sum = 0;
		for (int i = 1; i < 9; i++) {
			sum += v[i];
		}
		cout << "#" << test_case << " " << round(sum/8) << endl;
	}
	return 0;
}