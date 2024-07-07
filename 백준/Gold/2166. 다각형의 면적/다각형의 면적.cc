#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int n;

long double Calc(int i, int j) {
	long double x1 = v[0].first;
	long double y1 = v[0].second;
	long double x2 = v[i].first;
	long double y2 = v[i].second;
	long double x3 = v[j].first;
	long double y3 = v[j].second;

	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a , b });
	}

	long double sum = 0;
	for (int i = 1; i < n - 1; i++) {
		sum += Calc(i, i + 1);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(sum);

	return 0;
}