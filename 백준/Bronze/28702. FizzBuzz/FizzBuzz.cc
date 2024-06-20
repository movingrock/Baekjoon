#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	int answer = 0;
	if (a != "Fizz" && a != "Buzz" && a != "FizzBuzz") answer = stoi(a) + 3;
	else if (b != "Fizz" && b != "Buzz" && b != "FizzBuzz") answer = stoi(b) + 2;
	else if (c != "Fizz" && c != "Buzz" && c != "FizzBuzz") answer = stoi(c) + 1;

	if (answer % 3 == 0 && answer % 5 == 0) cout << "FizzBuzz";
	else if (answer % 3 == 0) cout << "Fizz";
	else if (answer % 5 == 0) cout << "Buzz";
	else cout << answer;

	return 0;
}