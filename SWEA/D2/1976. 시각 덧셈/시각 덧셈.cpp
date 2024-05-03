#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2;

		int h, m;

		h = h1 + h2 + (m1 + m2) / 60;
		if (h > 12) h -= 12;
		m = (m1 + m2) % 60;
		
		cout << "#" << test_case << " " << h << " " << m << endl;
	}
	return 0;
}