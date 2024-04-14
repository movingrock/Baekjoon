#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[8];
int answer = 0;

void dfs(int k, int clear, vector<vector<int>> dungeons){
    cout << clear << "\n";
    answer = max(answer, clear);
    for(int i= 0; i<dungeons.size(); i++){
        if(!visited[i] && k>=dungeons[i][0]){
            visited[i] = true;
            dfs(k-dungeons[i][1], clear+1, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dfs(k, 0, dungeons);
    
    return answer;
}