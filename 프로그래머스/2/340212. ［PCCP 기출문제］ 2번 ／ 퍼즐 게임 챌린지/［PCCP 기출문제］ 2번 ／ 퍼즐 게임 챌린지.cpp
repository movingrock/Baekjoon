#include <string>
#include <vector>

using namespace std;

long long solve(int level, vector<int> diffs, vector<int> times){
    long long sum = 0;
    for(int i = 0; i<diffs.size(); i++){
        if(diffs[i] <= level) sum += times[i];
        else sum += ((diffs[i]-level) * (times[i]+times[i-1]) + times[i]);
    }
                                        
    return sum;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int min = 1;
    int max = 100000;
    int level = (min+max)/2;
    
    while(min <= max){      
        level = (min+max)/2;
        
        if(solve(level, diffs, times) <= limit){
            answer = level;
            max = level - 1;       
        }else{
            min = level + 1;
        }
    }
    
    return answer;
}