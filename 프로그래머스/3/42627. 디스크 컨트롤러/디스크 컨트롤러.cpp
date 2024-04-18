#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int time = 0;
    int cnt = 0; // 들어간 일 개수
    while(!pq.empty() || cnt < jobs.size()){
        if(cnt < jobs.size() && jobs[cnt][0] <= time){
            pq.push({jobs[cnt][1], jobs[cnt][0]});
            cnt++;
            continue;
        }
        
        if(!pq.empty()){
            time += pq.top().first;
            answer += time - pq.top().second;
            pq.pop();
        }
        else{
            time = jobs[cnt][0];
        }
        
    }
    
    answer = answer/jobs.size();
    
    return answer;
}
