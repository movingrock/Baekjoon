#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201] = {0,};

vector<int> v[201];

void dfs(int x, vector<vector<int>>& computers){
    visited[x] = true;
    for(int i = 0; i<computers.size(); i++){
        if(computers[x][i] == 1 && !visited[i]){
            dfs(i, computers);
        }
    }
}

void bfs(int x, vector<vector<int>>& computers) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0; i<v[node].size(); i++){
            int nNode = v[node][i];
            if(!visited[nNode]){
                q.push(nNode);
                visited[nNode] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i= 0; i<computers.size(); i++){
        for(int j = 0; j<computers[0].size(); j++){
            if(computers[i][j]){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    for(int i= 0; i<n; i++){
        if(!visited[i]) {
            bfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}