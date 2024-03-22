#include <string>
#include <vector>
#include <climits>

using namespace std;

bool visited[50];
int ans = INT_MAX;

void dfs(string begin, string target, vector<string> &words, int step){
    if(begin == target) {ans = min(ans, step); return;} // 최소루트를 찾아야된다면 변경
    if(step >= ans) return;
    
    for(int i = 0; i<words.size(); i++){
        if(visited[i]) continue;
        
        int cnt = 0;
        for(int j = 0; j<begin.length(); j++){
            if(begin[j] == words[i][j]) cnt++;
        }
        
        if(cnt == begin.length()-1) {
            visited[i] = true;
            dfs(words[i], target, words, step+1);
            visited[i] = false;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool ispossible = false;
    for(int i= 0; i<words.size(); i++){
        if(target == words[i]) ispossible = true;
    }
    

    if(ispossible) {
        dfs(begin, target, words, 0);
        answer = ans;
    }
    else answer = 0;
    
    return answer;
}