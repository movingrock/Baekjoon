#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> v(n+1, vector<bool>(n+1, false));

    for(int i = 0; i<results.size(); i++){
        v[results[i][0]][results[i][1]] = true;
    }
    
    // j가 i를 이기고  i가 k를 이겼다면, j는 k를 이긴것이다.
    for(int i = 1; i<=n; i++){ // b
        for(int j = 1; j<=n; j++){ 
            for(int k = 1; k<=n; k++){
                if(v[j][i] && v[i][k]) v[j][k] = true;
            }
        }
    }
    
    // 선수 세기
    for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(int j = 1; j<=n; j++){
            if(v[i][j] || v[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    
    
    return answer;
}