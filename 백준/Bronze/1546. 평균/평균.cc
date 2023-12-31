#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double n;
	double arr[1001];
	cin >> n;
	double max_score = 0;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		max_score = max(max_score, arr[i]);
	}

	for (int i = 0; i < n; i++) {
		sum += ((arr[i] / max_score) * 100);
	}

	cout << fixed;
	cout.precision(6);
	cout << sum / n;

	return 0;
}