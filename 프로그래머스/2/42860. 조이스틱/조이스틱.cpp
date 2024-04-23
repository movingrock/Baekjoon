#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int sum = 0;
    for(int i = 0; i<name.length(); i++){
        sum += min(abs(name[i] - 'A'), abs('Z' - name[i]) + 1);
    }
    answer = sum;
    
    int len = name.length();
    int move = name.length() - 1;
    int next;
    for(int i = 0; i<name.length(); i++){
        next = i + 1;
        
        // A가 안나올때까지 next 이동
        while(next < name.length() && name[next] == 'A') next++;
        
        // move 값은 최대 length()-1이고 , 정방향 후 역방향 + 역방향 후 정방향의 합 의 최솟값
        // i + (len - next)는 정방향이동 + 역방향이동
        // min(i, len - next)는 정방향이동과 역방향 이동중에 짧은거 선택
        // 짧은 쪽으로 갔다가 다시 원점으로 돌아오고 반대방향으로 갈거기 때문
        move = min(move, i + (len - next) + min(i, len - next));
    }
     answer += move;
    
    return answer;
}