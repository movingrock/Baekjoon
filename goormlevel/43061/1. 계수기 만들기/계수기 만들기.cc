#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int limit[9];
	int num[9];
	for(int i = 1; i<=n; i++){
		cin >> limit[i];
	}
	
	for(int i =1; i<=n; i++){
		cin >> num[i];
	}
	
	int k;
	cin >> k;
	
	while(k--){
		int curr_n = n;
		num[curr_n]++;
		while(curr_n > 0){
			if(num[curr_n] > limit[curr_n]){
				num[curr_n] = 0;
				curr_n--;
				num[curr_n]++;
				
			}
			else{
				break;
			}
		}
	}
	
	for(int i = 1; i<=n; i++){
		cout << num[i];
	}
}