#include <iostream>
using namespace std;

int Factorial(int n){
	if(n == 1) return 1;
	return n * Factorial(n-1);
}

int main() {
	int n;
	cin >> n;
	if(n == 0){
		cout << 1;
		return 0;
	}
	else if(n >= 6){
		cout << 9;
		return 0;
	}else{
		int num = Factorial(n);
		while(num >= 10){
			int sum = 0;
			int curr = num;
			while(curr!= 0){
				sum += curr % 10;
				curr /= 10;
			}
			num = sum;
		}
		cout << num;
	}
}
