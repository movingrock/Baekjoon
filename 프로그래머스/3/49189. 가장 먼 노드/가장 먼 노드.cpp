#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[20001];
bool visited[20001];
int dist[20001];
int max_cnt = 0;

void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        max_cnt = max(max_cnt, cnt);
        dist[x] = cnt;
        
        for(int i = 0; i<v[x].size(); i++){
            int y = v[x][i];
            if(!visited[y]){
                visited[y] = true;
                q.push(make_pair(y, cnt+1));
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0; i<edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs();
    
    for(int i = 2; i<=n; i++){
        if(dist[i] == max_cnt) answer++;
    }
    
    return answer;
}