#include <iostream>
#include <cstring>
using namespace std;

bool visited[10] = { 0, };

bool isAll() {
	for (int i = 0; i < 10; i++) {
		if (!visited[i]) return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int k = 1;
		memset(visited, false, sizeof(visited));
		while (!isAll()) {
			int m = n * k;
			while (m != 0) {
				visited[m % 10] = true;
				m /= 10;
			}
			k++;
		}

		cout << "#" << test_case << " " << (k - 1) * n << endl;
	}
	return 0;
}