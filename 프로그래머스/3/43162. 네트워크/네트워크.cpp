#include <string>
#include <vector>

using namespace std;

bool visited[201] = {0,};

void dfs(int x, vector<vector<int>>& computers){
    visited[x] = true;
    for(int i = 0; i<computers.size(); i++){
        if(computers[x][i] == 1 && !visited[i]){
            dfs(i, computers);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i= 0; i<n; i++){
        if(!visited[i]) {
            dfs(i, computers); answer++;}
    }
    
    return answer;
}