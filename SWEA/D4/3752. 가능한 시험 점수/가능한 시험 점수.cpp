#include <iostream>
#include <vector>

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
		bool visited[10000] = { 0, };
		vector<int> v;
		visited[0] = true;
		v.push_back(0);

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			int v_size = v.size();

			for (int j = 0; j < v_size; j++) {
				int sum = v[j] + num;
				if (!visited[sum]) {
					v.push_back(sum);
					visited[sum] = true;
				}
			}

		}

		int answer = 0;
		for (int i = 0; i < 10000; i++) {
			if (visited[i]) answer++;
		}
		

		cout << "#" << test_case << " " << answer << endl;

	}
	return 0;
}