#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int dx[4] ={0, 1, 0, -1};
int dy[4] ={1, 0, -1, 0}; 

bool InRange(int x, int y, int n, int m){
    return x>=0 && x<n && y>=0 && y<m;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int n = land.size();
    int m = land[0].size();
    int id = 0;
    
    int visited[n][m];
    memset(visited, -1, sizeof(visited));
    vector<int> oil;
    
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(land[i][j] == 1 && visited[i][j] == -1) {
                visited[i][j] = id;
                int cnt = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int d = 0; d<4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(InRange(nx, ny, n, m) && land[nx][ny] == 1 && visited[nx][ny] == -1){
                            q.push({nx, ny});
                            visited[nx][ny] = id;
                            cnt++;
                        }
                    }
                }
                
                oil.push_back(cnt);
                id++;
            }
        }
    }
    
    for(int j =0; j<m; j++){
        set<int> groups;
        for(int i =0; i<n; i++){
            if(visited[i][j] != -1) groups.insert({visited[i][j]});    
        }
        
        
        
        int sum = 0;
        for(int g: groups){
            sum += oil[g];
        }
        answer = max(answer, sum);
    }
    
    
    return answer;
}

























