#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0 ; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K && pq.size() > 1){
        answer++;
        int s1 = pq.top(); pq.pop();
        int s2 = pq.top(); pq.pop();
        int sco = s1 + s2*2;
        pq.push(sco);
    }
    if(pq.top() < K) answer = -1;
    

    // for(int i = 0; i<scoville.size(); i++){
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    
    return answer;
}