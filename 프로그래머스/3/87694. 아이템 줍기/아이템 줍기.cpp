#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int  grid[101][101] = {0, };
bool visited[101][101] = {0,};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y){
    return x>=0 && x<101 && y>=0 && y<101;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = INT_MAX;

    // 좌표2배하고 둘레만 1로 칠함.
    for(int i = 0;i<rectangle.size(); i++){
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int j = x1; j<=x2; j++){
            for(int k = y1; k<=y2; k++){
                grid[j][k] = 1;
            }
        }
    }
    // 가운데는 0으로 칠함
    for(int i = 0;i<rectangle.size(); i++){
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int j = x1+1; j<x2; j++){
            for(int k = y1+1; k<y2; k++){
                grid[j][k] = 0;
            }
        }
    }
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // bfs();
    queue<pair<pair<int, int>, int>> q;
    q.push({{characterX, characterY}, 0});
    visited[characterX][characterY] = true;
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(cx == itemX && cy == itemY){
            answer = min(answer, cnt);
        }
        
        for(int i =0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 1){
                q.push({{nx, ny}, cnt+1});
                visited[nx][ny] = true;
            }
        }
        
    }

    
    answer /= 2;
    
    return answer;
}