#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>());

    for(int i = citations[0]; i >= 0; i--){ // 비교 기준
        int cnt = 0;
        for(int j = 0; j<citations.size(); j++){
            if(i <= citations[j]) cnt++;
        }
        if(cnt >= i) {
            answer = i;
            break;
        }
    }
    

    
    return answer;
}
