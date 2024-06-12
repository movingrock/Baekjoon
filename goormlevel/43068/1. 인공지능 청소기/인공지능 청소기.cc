#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int x, y, n;
		cin >> x >> y >> n;
		int dis = abs(x) + abs(y);
		if(dis > n){
			cout << "NO\n";
		}else{
			if((n - dis) %2 == 0) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}