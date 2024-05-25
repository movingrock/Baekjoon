#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int out[1000001] = {0, };
int in[1000001] = {0, };

vector<vector<int>> v(1000001);
    
int donut = 0;
int stick = 0;
int eight = 0;

void bfs(int start){
    queue<int> q;
    q.push(start);
    bool isStart = false;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        if(node == start && isStart) {
            donut++;
            return;
        }
        else if(v[node].size() >=2) {
            eight++;
            return;
        }
        
        for(int i =0; i<v[node].size(); i++){
            q.push(v[node][i]);
        }
        isStart = true;
    }
    stick++;
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    int max_num =0;
    for(int i = 0; i<edges.size(); i++){
        out[edges[i][0]]++;
        in[edges[i][1]]++;
        v[edges[i][0]].push_back(edges[i][1]);
        max_num = max({max_num, edges[i][0], edges[i][1]});
    }
    
    int start = 0;
    for(int i =0; i <= max_num; i++ ){
        if(in[i] == 0 && out[i] >= 2){
            start = i;
            answer.push_back(i);
            break;
        }
    }

    
    vector<int> node = v[start];
    for(int i= 0; i<node.size(); i++){
        bfs(node[i]);
    }
    
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    
    return answer;
}