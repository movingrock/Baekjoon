#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.length();
    int cnt = 0;

    // 0부터 k까지 제일 큰숫자 중 제일 앞에 있는거 찾기
    while(k >0 && cnt < n && answer.length() < n - k){
        int max_index = INT_MAX;
        int max_num = INT_MIN;
        for(int i = cnt; i< cnt+k+1 && i < n; i++){
            if(max_num < number[i] - '0') max_index = i;
            max_num = max(max_num, number[i] - '0');
        }
        answer.push_back(number[max_index]);
        
        k -= (max_index - cnt);
        cnt = max_index+1;
    }
    
    if(k > 0) cnt = cnt + k;
    
    if(cnt < number.length()){
        for(int i = cnt; i < number.size(); i++){
            answer.push_back(number[i]);
        }
    }
    
    return answer;
}