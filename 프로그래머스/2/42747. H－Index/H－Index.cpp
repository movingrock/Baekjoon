#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<>());

    for(int h = citations[0]; h >= 0; h--){ // 비교 기준 h
        int cnt = 0;
        for(int i = 0; i<citations.size(); i++){
            if(h <= citations[i]) cnt++;
        }
        if(cnt >= h) {
            answer = h;
            break;
        }
    }
    
    return answer;
}
