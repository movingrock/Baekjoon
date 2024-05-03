#include<iostream>
#include <vector>
#include <algorithm>
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
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());

		cout << "#" << test_case << " ";
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}