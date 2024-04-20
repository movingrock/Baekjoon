#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    sort(people.begin(), people.end());
    
    for(int i= 0 ;i<people.size(); i++){
        dq.push_back(people[i]);
    }

    
    while(!dq.empty()){
        if(dq.size() >= 2 && dq.back() + dq.front() <= limit){
            answer++;
            dq.pop_back();
            dq.pop_front();
        }else{
            dq.pop_back();
            answer++;
        }
    }
    
    return answer;
}
