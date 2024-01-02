#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, v;
	cin >> a >> b >> v;

	int date = 1;
	date += (v - a) / (a - b);
	if ((v - a) % (a - b) != 0) date++;
	if (a >= v) cout << 1;
	else cout << date;

	return 0;
}