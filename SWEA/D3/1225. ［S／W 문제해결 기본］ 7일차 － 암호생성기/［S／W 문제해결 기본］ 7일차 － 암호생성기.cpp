#include<iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tc; cin >> tc;
		queue<int> q;
		for (int i = 0; i < 8; i++) {
			int num; cin >> num;
			q.push(num);
		}

		int cnt = 1;
		while (true) {
			if (q.front() - cnt <= 0) {
				q.pop();
				q.push(0);
				break;
			}
			else {
				q.push(q.front() - cnt);
				q.pop();
				cnt++;
			}
			if (cnt == 6) cnt = 1;
		}

		cout << "#" << test_case << " ";
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
	return 0;
}