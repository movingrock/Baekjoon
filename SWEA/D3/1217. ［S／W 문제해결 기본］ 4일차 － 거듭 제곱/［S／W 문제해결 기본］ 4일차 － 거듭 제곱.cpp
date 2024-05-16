#include<iostream>

using namespace std;

int tc, a, b;

int Func(int answer, int cnt) {
	if (cnt == b) return answer;

	Func(answer * a, cnt+1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> tc;
		cin >> a >> b;

		cout << "#" << test_case << " " << Func(1, 0) << endl;
	}
	return 0;
}