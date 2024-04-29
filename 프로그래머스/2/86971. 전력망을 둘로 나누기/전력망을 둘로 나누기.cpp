#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

vector<int> v[101];

int arr[100] = {0, };

void bfs(int start, int num){
    queue<int> q;
    q.push(start);
    arr[start] = num;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i<v[x].size(); i++){
            int y = v[x][i];
            if(!arr[y]){
                q.push(y);
                arr[y] = num;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    // i번째 wire를 끊었다고 가정
    for(int i= 0; i<wires.size(); i++){ 
        int num1 = 0;
        int num2 = 0;
        
        // vector, arr 초기화
        for(int j = 1; j<=n; j++){
            v[j].clear();
            arr[j] = 0;
        }
        
        // i번째 wire를 제외하고 연결된 값을 넣어줌.
        for(int j= 0; j<wires.size(); j++){
            if(i == j) continue;
            v[wires[j][0]].push_back(wires[j][1]);
            v[wires[j][1]].push_back(wires[j][0]);
        }
        
        // bfs로 두 그래프를 1과 2로 나눔.
        bfs(wires[i][0], 1);
        bfs(wires[i][1], 2);
        
        // 1과 2의 개수를 셈.
        for(int j = 1; j<=n; j++){
            if(arr[j] == 1) num1++;
            else if(arr[j] == 2) num2++;
        }
        
        // 두 집단의 개수 차의 최솟값을 반환
        answer = min(answer, abs(num1 - num2));

    }
    
    
    return answer;
}