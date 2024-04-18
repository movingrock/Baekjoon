#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

vector<int> v[101];

int arr[100] = {0, };

void bfs(int start, int color){
    queue<int> q;
    q.push(start);
    arr[start] = color;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i<v[x].size(); i++){
            int y = v[x][i];
            if(!arr[y]){
                q.push(y);
                arr[y] = color;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    for(int i= 0; i<wires.size(); i++){ // i번째 wire를 끊었다고 가정
        int num1 = 0;
        int num2 = 0;
        for(int j = 1; j<=n; j++){
            v[j].clear();
            arr[j] = 0;
        }
        for(int j= 0; j<wires.size(); j++){ // j개 순환
            if(i == j) continue;
            v[wires[j][0]].push_back(wires[j][1]);
            v[wires[j][1]].push_back(wires[j][0]);
        }
        
        cout << wires[i][0] << " " << wires[i][1] << endl;
                    
        bfs(wires[i][0], 1);
        bfs(wires[i][1], 2);
        
    
        
        for(int j = 1; j<=n; j++){
            cout << arr[j] << " ";
            if(arr[j] == 1) num1++;
            else if(arr[j] == 2) num2++;
        }
        cout << endl;
        answer = min(answer, abs(num1 - num2));
        cout << "num1: " << num1 << " num2: " << num2 << endl;
    }
    
    
    return answer;
}