#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, a, b, c;
	cin >> n;
	long long answer = n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		if (v[i] - b <= 0) continue;
		if ((v[i] - b) % c == 0) answer += (v[i] - b) / c;
		else answer += (v[i] - b) / c + 1;
	}

	cout << answer;
	return 0;
}
