#include <iostream>
using namespace std;

int grid[41][41];
int copyG[41][41];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y){
	return x>=0 && x<n && y>=0 && y<n;
}

bool Check(){
	for(int i=0; i<n; i++){
		for(int j =0; j<n; j++){
			if(grid[i][j] != 0) return false;
		}
	}
	return true;
}

int main() {	
	cin >> n;
	for(int i =0; i<n; i++){
		for(int j =0 ; j<n; j++){
			cin >> grid[i][j];
		}
	}
	
	int answer = 0;
	while(!Check()){
		answer++;
		for(int i = 0; i<n; i++){
			for(int j =0; j<n; j++){
				if(grid[i][j] == 0){
					copyG[i][j] = grid[i][j];
				}else{
					int cnt = 0;
					for(int k = 0; k<4; k++){
						int nx = i+dx[k];
						int ny = j+dy[k];
						if(InRange(nx, ny) && grid[nx][ny] == 0) cnt++;
					}
					if(grid[i][j] - cnt < 0) copyG[i][j] = 0;
					else copyG[i][j] = grid[i][j] - cnt;
				}
		
			}
		}
		for(int i=0; i<n; i++){
			for(int j =0; j<n; j++){
				grid[i][j] = copyG[i][j];
			}
		}
	}
	
	cout << answer;
	
	return 0;
}