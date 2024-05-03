#include<iostream>

using namespace std;

struct document {
	char c;
	int num;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		document doc[10];
		for (int i = 0; i < n; i++) {
			cin >> doc[i].c >> doc[i].num;
		}


		cout << "#" << test_case << endl;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < doc[i].num; j++) {
				cout << doc[i].c;
				cnt++;
				if (cnt == 10) {
					cout << endl;
					cnt = 0;
				}
			}

		}

		cout << endl;
	}
	return 0;
}