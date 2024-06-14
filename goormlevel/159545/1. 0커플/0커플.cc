#include <iostream>
#include <set>

using namespace std;
int main() {
	int n;
	cin >> n;
	set<int> s;
	for(int i = 0; i<n; i++){
		int num;
		cin >> num;
		if(s.find(-num) != s.end()) s.erase(-num);
		else s.insert(num);
	}
	
	int answer = 0;
	
	for(auto iter = s.begin(); iter != s.end(); iter++){
		answer += *iter;
	}
	
	cout << answer;

	return 0;
}