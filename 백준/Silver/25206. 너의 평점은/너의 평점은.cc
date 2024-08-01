#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

double Func(string result) {
	if (result == "A+") return 4.5;
	else if (result == "A0") return 4.0;
	else if (result == "B+") return 3.5;
	else if (result == "B0") return 3.0;
	else if (result == "C+") return 2.5;
	else if (result == "C0") return 2.0;
	else if (result == "D+") return 1.5;
	else if (result == "D0") return 1.0;

	return 0.0;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	double answer = 0.0;
	double sum = 0.0;
	cout << fixed;
	cout.precision(6);
	for (int i = 0; i < 20; i++) {
		string name, grade;
		double score;
		cin >> name >> score >> grade;

		if (grade == "P") continue;
		answer += score * Func(grade);
		sum += score;
	}

	cout << (double)answer / (double)sum;

	return 0;
}