#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	double sum = 0.0;
	int freq = 0;
	int freqB = 1;
	int cnt = 0;
	int value = v[0];
	int freq_value = v[0];

	for (int i = 0; i < n; i++) {
		sum += v[i];

		if (value == v[i]) cnt++;
		else { value = v[i]; cnt = 1; }

		freq = max(freq, cnt);
		if (freq > freqB) s.clear();
		if (freq == cnt) { freq_value = value; s.insert(freq_value); }
		
		freqB = freq;
	}
	// 1
	if (round(sum / n) == -0) cout << 0 << "\n";
	else cout << round(sum / n) << "\n";

	// 2
	cout << v[n / 2] << "\n";

	// 3
	auto it = s.begin();
	advance(it, 1);

	if (it != s.end()) {
		cout << *it << "\n";
	}
	else {
		advance(it, -1);
		cout << *it << "\n";
	}

	//4
	cout << v[n - 1] - v[0];

	return 0;
}