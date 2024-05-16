#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc; cin >> tc;
		string find; cin >> find;
		string src; cin >> src;
		int answer = 0;

		for (int i = 0; i < src.length(); i++) {
			bool isTrue = true;
			for (int j = 0; j < find.length(); j++) {
				if (src[i + j] != find[j]) isTrue = false;
			}
			if (isTrue) answer++;
		}


		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}