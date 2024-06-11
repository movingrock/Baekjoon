#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> v[17];
int answer = 0;

void dfs(int node, int sheep, int wolf, vector<int> info, vector<int> next){
    if(info[node] == 0) sheep++;
    else wolf++;
    
    answer = max(answer, sheep);
    
    if(wolf >= sheep) return;
    
    for(int i =0; i<next.size(); i++){
        vector<int> n = next;
        n.erase(n.begin()+i);
        for(int j =0 ; j<v[next[i]].size(); j++){
            n.push_back(v[next[i]][j]);
        }
        dfs(next[i], sheep, wolf, info, n);
    }
    
}


int solution(vector<int> info, vector<vector<int>> edges) {
    
    for(int i =0; i<edges.size(); i++){
        v[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int> next;
    for(int i=0; i<v[0].size(); i++){
        next.push_back(v[0][i]);
    }
    
    dfs(0, 0, 0, info, next);
    
    return answer;
}