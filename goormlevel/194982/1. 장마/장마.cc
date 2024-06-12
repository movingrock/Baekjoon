#include <iostream>
using namespace std;

int arr[1001];
bool visited[1001];
int n, m;

void initialize(){
	for(int i=1; i<=n; i++){
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	for(int i =1; i<=n; i++){
		cin >> arr[i];
	}
	
	for(int i = 1; i<=m; i++){
		int s, e;
		cin >> s >> e;
		for(int  j = s; j<=e; j++){
			arr[j]++;
			visited[j] = true;
		}
		
		if(i % 3 == 0) {
			for(int j = 1; j<=n; j++){
				if(visited[j]) arr[j]--;
			}
			initialize();
		}
	}
	
	for(int i =1; i<=n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}