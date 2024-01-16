#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num; cin >> num;
			v.push_back(num);
		}
		else if (str == "pop") {
			if (!v.empty()) { cout << v.back() << "\n"; v.pop_back(); }
			else cout << "-1\n";
		}
		else if (str == "size") cout << v.size() << "\n";
		else if (str == "empty") {
			if (v.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "top") {
			if (v.empty()) cout << "-1\n";
			else cout << v.back() << "\n";
		}
	}
	return 0;
}