#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	int k;
	char c; int n;
	cin >> t;
	while (t--) {
		multiset<int> s;
		
		cin >> k;
		while (k--) {
			cin >> c >> n;
			if (c == 'I') {
				s.insert(n);
			}
			else if (!s.empty() && c == 'D') {
				if (n == 1) {
					auto iter = s.end();
					iter--;
					s.erase(iter);
				}
				else if (n == -1) {
					s.erase(s.begin());
				}
			}
		}
		if (s.empty()) cout << "EMPTY\n";
		else {
			auto iter = s.end();
			iter--;
			cout << *iter << " " << *s.begin() << "\n";
		}
	}

	return 0;
}