#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int answer = 0;
	while (n--) {
		string str;
		cin >> str;
		bool flag = true;
		vector<int> v[26];

		for (int i = 0; i < str.length(); i++) {
			v[(int)str[i]-97].push_back(i);
		}

		for (int i = 0; i < 26; i++) {
			if (v[i].size() == 0) continue;

			for (int j = 0; j < v[i].size()-1; j++) {
				if (v[i][j] + 1 != v[i][j + 1]) flag = false;

			}
			
		}

		if (flag) answer++;
	}
	
	cout << answer;

	return 0;
}