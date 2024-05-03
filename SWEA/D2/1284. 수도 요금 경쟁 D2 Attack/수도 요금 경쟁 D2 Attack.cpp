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
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;
		int a = w * p;
		int b;
		if (w <= r) {
			b = q;
		}
		else {
			b = q + (w - r) * s;
		}
		
		cout << "#" << test_case << " " << min(a, b) << endl;
	}
	return 0;
}