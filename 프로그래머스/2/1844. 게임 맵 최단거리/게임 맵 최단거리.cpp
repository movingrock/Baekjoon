#include<vector>
#include <queue>

using namespace std;

bool visited[101][101];
int grid[101][101] = {0, };

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool InRange(int x, int y, vector<vector<int>> &maps){
    return x>=0 && x<maps.size() && y>=0 && y < maps[0].size();
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    grid[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i= 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(InRange(nx, ny, maps) && maps[nx][ny] == 1 && !visited[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                grid[nx][ny] = grid[x][y] + 1;
            }
        }

    }
    
    if(grid[maps.size() - 1][maps[0].size() - 1] == 0) answer = -1;
    else answer = grid[maps.size() - 1][maps[0].size() - 1];
    
    return answer;
}