#include <iostream>
#include <cmath>

using namespace std;
int main() {
	double n, m;
	cin >> n >> m;
	double salt = n * 7.00 / 100.00;
	double water = m + n;
	cout << fixed;
	cout.precision(2);
	
	double answer = floor(salt / water * 10000)/100;
	
	cout << answer;
	
	return 0;
}