#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> days;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i = 0; i<progresses.size(); i++){
        days.push_back(ceil( (double)(100-progresses[i] ) / speeds[i]));
        // cout << days[i] << " ";
    }
    
    int max_before = days[0];
    int cnt = 1;
    
    for(int i = 1; i<days.size(); i++){
        if(max_before >= days[i]) cnt++;
        
        if(max_before < days[i]){
            answer.push_back(cnt);
            cnt = 1;
            max_before = days[i];
        }
        
        if(i == days.size()-1) answer.push_back(cnt);
    }
    
    return answer;
}