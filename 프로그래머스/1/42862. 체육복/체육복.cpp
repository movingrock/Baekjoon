#include <string>
#include <vector>
#include <iostream>

using namespace std;

int student[31] = {0, };

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i= 1; i<=n; i++){
        student[i] = 1;
    }
    
    for(int i= 0; i<reserve.size(); i++){
        student[reserve[i]]++;
    }
    
    for(int i = 0; i<lost.size(); i++){
        student[lost[i]]--;
    }
    
    for(int i = 1; i<=n; i++){
        if(student[i] == 0){
            if(i>=2 && student[i-1] >= 2){
                student[i-1]--;
                student[i]++;
            }else if(i <= n-1 && student[i+1] >=2){
                student[i+1]--;
                student[i]++;
            }
                
        }
    }
    
    for(int i = 1; i<=n; i++){
        if(student[i] >= 1) answer++;
    }
    
    
    return answer;
}