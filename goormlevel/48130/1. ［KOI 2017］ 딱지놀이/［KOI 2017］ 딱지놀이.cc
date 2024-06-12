#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--){
		int a, b;
		int aArr[5] = {0, };
		int bArr[5] = {0, };
		
		cin >> a;
		for(int i = 0; i<a; i++){
			int num;
			cin >> num;
			aArr[num]++;
		}
		
		cin >> b;
		for(int i = 0; i<b; i++){
			int num;
			cin >> num;
			bArr[num]++;
		}
		
		bool isSame = true;
		for(int i = 4; i>=1; i--){
			if(aArr[i] > bArr[i]){
				cout << "A" << endl;
				isSame = false;
				break;
			}
			else if(aArr[i] < bArr[i]){
				cout << "B"<< endl;
				isSame = false;
				break;
			}
		}
		if(isSame) cout << "D" << endl;
	}
	cout << endl;
	return 0;
}