#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_diff = 0;
vector<int> answer;

int num = 1;

void Backtracking(int cnt, int index, vector<int> info, vector<int> ryan, int n){
    if(cnt == n){

        int apeachS = 0;
        int ryanS = 0;
        for(int i=0; i<ryan.size(); i++){
            if(info[i] == 0 && ryan[i] == 0) continue;
            if(info[i] >= ryan[i]) apeachS += (10-i);
            else ryanS += (10 - i);
        }
        
        int diff = ryanS - apeachS;
        
        if(ryanS > apeachS && diff > max_diff){           
            answer = ryan;
            max_diff = diff;
        }else if(diff == max_diff && ryanS > apeachS){
            for(int i = 10; i>=0; i--){
                if(answer[i] > ryan[i]) return;
                else if(answer[i] < ryan[i]){
                    answer = ryan;
                    break;
                }
            }
        }
        
        return;
    }
    for(int i = index; i <= 10; i++){
        int num = info[i] + 1;
        if(num > n- cnt) num = n-cnt;
        ryan[i] = num;
        Backtracking(cnt + num, index+1, info, ryan, n);        
        ryan[i] = 0;
    }
    
}


vector<int> solution(int n, vector<int> info) {
    vector<int> ryan = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    Backtracking(0, 0, info, ryan, n);
    
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}