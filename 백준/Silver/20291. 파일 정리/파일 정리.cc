#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	map<string, int> m;
	vector<pair<int, string>> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		istringstream iss(str);
		string buffer;
		vector<string> result;

		while (getline(iss, buffer, '.')) {
			result.push_back(buffer);
		}
		if (m.find(result[1]) != m.end()) m[result[1]]++;
		else m.insert({ result[1], 1 });
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		v.push_back({ iter->second, iter->first });
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " " << v[i].first << endl;
	}

	return 0;
}