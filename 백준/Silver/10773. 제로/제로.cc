#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int k;
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num > 0) s.push(num);
		else if (num == 0) s.pop();
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	
	cout << sum;
	return 0;
}