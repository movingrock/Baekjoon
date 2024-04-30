#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define INF 99999999

using namespace std;

vector<pair<int, int>> v[101];
bool visited[101] = {0, };
int dist[101] = {0, };
int answer = 0;


void bfs(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    for(int i = 0; i<v[0].size(); i++){
        q.push({v[0][i].second, v[0][i].first});
    }
    visited[0] = true;
    
    while(!q.empty()){
        int node = q.top().second;
        int cnt = q.top().first;
        q.pop();
        
        if(!visited[node]){
            visited[node] = true;
            answer += cnt;
            for(int i =0; i<v[node].size(); i++){
                int nNode = v[node][i].first;
                int nCnt = v[node][i].second;
                
                if(!visited[nNode]){
                    q.push({nCnt, nNode});
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    
    for(int i= 0; i<n; i++){
        dist[i] = INF;
    }
    
    for(int i= 0; i<costs.size(); i++){
        v[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        v[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    bfs();
    
    return answer;
}