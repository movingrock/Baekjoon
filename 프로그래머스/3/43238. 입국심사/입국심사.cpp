#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long min = 1;
    long long max = n * (long long)times.back();
    
    while(min <= max){
        long long avg = (min+max) / 2;
        long long sum = 0; // '심사위원마다 avg시간동안 처리할 수 있는 인원수'의 합
        
        for(int i= 0; i<times.size(); i++){
            sum += avg / (long long) times[i];
        }
        
        if(sum >= n){
            max = avg-1;
            answer = avg;
        }else min = avg + 1;
    }
    
    return answer;
}