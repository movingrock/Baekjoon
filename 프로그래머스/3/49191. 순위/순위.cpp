#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> v(n+1, vector<bool>(n+1, false));

    for(int i = 0; i<results.size(); i++){
        v[results[i][0]][results[i][1]] = true;
    }
    
    // a가 b를 이기고 b가 c를 이기면 a는 c를 이긴다
    for(int i = 1; i<=n; i++){ // 중간노드
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                if(v[j][i] && v[i][k]) v[j][k] = true;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(int j = 1; j<=n; j++){
            if(v[i][j] || v[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    
    
    return answer;
}

// 알 수 있는거
// 경기를 n-1번 한 선수가 있다면 그 선수의 등수를 알 수 있음
// 그 선수를 기준으로 이기거나 진 선수를 판별하고 그 중에서 또 알 수 있음